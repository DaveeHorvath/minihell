/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:58:30 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/19 22:57:06 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "env.h"

int	exec_pipeline(char *s)
{
	t_cmd	*head;
	t_cmd	*current;
	char	**commands;
	int		i;
	int		prev_out;

	i = 0;
	head = NULL;
	prev_out = -1;
	commands = ft_pusharr(ft_split(s, '|'));
	while (commands[i])
	{
		current = get_command(commands[i], commands, &prev_out, i);
		add_cmd(&head, current);
		if (current->exitcode != -1)
		{
			do_cmd(current);
			if (current->fd[0] != 0)
				close(current->fd[0]);
			if (current->fd[1] != 1)
				close(current->fd[1]);
		}
		i++;
	}
	return (wait_for_done(head));
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
	new->next = NULL;
}

static int	wait_for_done(t_cmd *head)
{
	int	status;
	int	exitstatus;

	exitstatus = 0;
	while (head)
	{
		if (head->exitcode != -1)
		{
			waitpid(head->pid, &status, 0);
			if (WIFEXITED(status))
				exitstatus = WEXITSTATUS(status);
		}
		else
			exitstatus = 1;
		head = head->next;
	}
	return (exitstatus);
}

static char	*get_path(char *name)
{
	const char	**path = (const char **)ft_pusharr(ft_split(msh_getenv("PATH"), ':'));
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
	if (access(ft_strjoin("./", name), F_OK) == 0)
		return (ft_push(ft_strjoin("./", name)));
	return (NULL);
}

static void	do_cmd(t_cmd *cmd)
{
	pid_t	id;
	char	*path;

	id = fork();
	if (id < 0)
		child_error();
	else if (id == 0)
	{
		path = get_path(cmd->argv[0]);
		if (!path && cmd->argv[0])
			cmd_not_found(cmd);
		else if (!path)
			exit(0);
		dup2(cmd->fd[0], 0);
		dup2(cmd->fd[1], 1);
		if (cmd->fd[0] != 0)
			close(cmd->fd[0]);
		if (cmd->fd[1] != 1)
			close(cmd->fd[1]);
		execve(path, cmd->argv, cmd->env);
	}
	else
		cmd->pid = id;
}
