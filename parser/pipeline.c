/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:58:30 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/05 22:50:30 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
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

	while (head)
	{
		waitpid(head->pid, &status, 0);
		head = head->next;
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WSTOPSIG(status));
	else
		return (0);
}

char	*get_path(char *name)
{
	const char	*path = ft_split(msh_getenv("PATH"), ':');
	char		*c_path;
	int			i;

	while (path[i])
	{
		c_path = ft_push(ft_strsjoin(path[i], name, '/'));
		if (access(c_path, F_OK))
			return (c_path);
		ft_pop();
		i++;
	}
	if (access(ft_strjoin("./", name), F_OK))
		return (ft_strjoin("./", name));
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
		if (dup2(cmd->fd[0], STDIN_FILENO) == -1
			|| dup2(cmd->fd[1], STDOUT_FILENO) == -1)
			child_error(cmd);
		path = get_path(cmd->argv[0]);
		if (!path)
			cmd_not_found();
		if (execve(path, cmd->argv, msh_getenv()) == -1)
		{
			free(path);
			childerror();
		}
	}
	else
		cmd->pid = id;
}

int	exec_pipeline(char *s)
{
	t_cmd	*head;
	t_cmd	*current;
	char	**commands;
	int		i;
	int		prev_out;

	i = 0;
	commands = ft_stupid_split(s);
	while (commands[i])
	{
		current = get_cmd(commands[i]);
		get_default_fds(&prev_out, current->fd);
		add_cmd(&head, current);
		do_cmd(current);
		i++;
	}
	return (wait_for_done(head));
}
