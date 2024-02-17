/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:58:30 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/17 19:43:49 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../libft/libft.h"

static char *msh_getenv(char *s)
{
	(void)s;
	return ("/Users/dhorvath/lbin/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
}

static void	add_cmd(t_cmd **head, t_cmd *new)
{
	t_cmd	*cur;

	cur = *head;
	if (!cur)
	{
		*head = new;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

static int	wait_for_done(t_cmd *head)
{
	int	status;
	int exitstatus = 0;

	while (head)
	{
		waitpid(head->pid, &status, 0);
		head = head->next;
	}
	return (exitstatus);
}

char	*get_path(char *name)
{
	const char	**path = (const char **)ft_push(ft_split(msh_getenv("PATH"), ':'));
	char		*c_path;
	int			i;

	i = 0;
	while (path[i])
	{
		c_path = ft_push(ft_strsjoin(path[i], name, '/'));
		if (access(c_path, F_OK) == 0)
			return (c_path);
		ft_pop();
		i++;
	}
	if (access(ft_strjoin("./", name), F_OK))
		return (ft_push(ft_strjoin("./", name)));
	return (NULL);
}

/* should be static */
void	do_cmd(t_cmd *cmd)
{
	pid_t	id;
	char	*path;

	id = fork();
	if (id < 0)
		child_error();
	else if (id == 0)
	{
		path = get_path(cmd->argv[0]);
		if (!path)
			cmd_not_found();
		if (dup2(cmd->fd[0], 0) == -1
			|| dup2(cmd->fd[1], 1) == -1)
			child_error();
		execve(path, cmd->argv, cmd->env);
	}
	else
		cmd->pid = id;
}

void	get_def_filedesc(int i, int need_pipe, int *prev_out, t_cmd *current)
{
	int	pipefds[2];

	if (need_pipe)
	{
		pipe(pipefds);
		current->fd[1] = pipefds[1];
		*prev_out = pipefds[0];
	}
	else
	{
		current->fd[1] = 1;
	}
	if (i != 0)
	{
		current->fd[0] = *prev_out;
	}
	else
	{
		current->fd[0] = 0;
	}
}

int	exec_pipeline(char *s)
{
	t_cmd	*head = NULL;
	t_cmd	*current;
	char	**commands;
	int		i;
	int		prev_out = -1;

	i = 0;
	commands = ft_pusharr(ft_split(s, '|'));
	while (commands[i])
	{
		current = get_command(commands[i]);
		if (commands[i + 1])
			get_def_filedesc(i, 1, &prev_out, current);
		else
			get_def_filedesc(i, 0, &prev_out, current);
		add_cmd(&head, current);
		do_cmd(current);
		if (current->fd[0] != 0)
			close(current->fd[0]);
		if (current->fd[1] != 1)
			close(current->fd[1]);
		i++;
	}
	close(prev_out);
	return (wait_for_done(head));
}
