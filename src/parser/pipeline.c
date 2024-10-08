/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:58:30 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/20 14:31:52 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "env.h"

static void	add_cmd(t_cmd **head, t_cmd *new);
static int	wait_for_done(t_cmd *head);
static char	*get_path(char *name);
static void	do_cmd(t_cmd *cmd);

/*
	executes just one pipeline
	everything runs in a fork, only if there is just 1 builtin command
	the main process is used
*/
int	exec_pipeline(char *s)
{
	const char	**commands = (const char **)ft_quoted_split(s, '|');
	t_cmd		*head;
	t_cmd		*current;
	int			i;
	int			prev_out;

	i = 0;
	head = NULL;
	prev_out = -1;
	while (commands[i])
	{
		save_pipeline(head, 1);
		if (i == 0 && !commands[1] && is_builtin((char *)commands[0], 0))
			return (exec_builtin((char *)commands[0], 1, 1));
		current = get_command((char *)commands[i], (char **)commands,
				&prev_out, i);
		add_cmd(&head, current);
		if (current->exitcode != -1)
			do_cmd(current);
		smart_closer(current->fd);
		i++;
	}
	return (wait_for_done(head));
}

/*
	appends command the linked list
*/
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

/*
	waits for all the pids and returns the last run processes exit code
*/
static int	wait_for_done(t_cmd *head)
{
	int	status;
	int	exitstatus;

	exitstatus = 0;
	while (head)
	{
		if (head->exitcode != -1)
			waitpid(head->pid, &status, 0);
		else
			exitstatus = 1;
		head = head->next;
	}
	if (WIFEXITED(status))
		exitstatus = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		exitstatus = WTERMSIG(status);
	return (exitstatus);
}

/*
	looks for name in the $PATH
*/
static char	*get_path(char *name)
{
	const char	**path = ft_pusharr(ft_split(msh_getenv("PATH"), ':'));
	char		*c_path;
	int			i;

	i = 0;
	if (ft_strequals("", name))
		return (0);
	if (access(ft_strjoin(msh_getenv("PWD"), name), F_OK) == 0)
		return (ft_push(ft_strjoin(msh_getenv("PWD"), name)));
	if (access(name, F_OK) == 0)
		return (name);
	if (!path)
	{
		ft_dprintf(2, "minishell: no such file or directory: %s\n", name);
		return ("");
	}
	while (path[i])
	{
		c_path = ft_push(ft_strsjoin(path[i], name, '/'));
		if (access(c_path, F_OK) == 0)
			return (c_path);
		ft_pop();
		i++;
	}
	return (NULL);
}

/*
	executes command
*/
static void	do_cmd(t_cmd *cmd)
{
	pid_t	id;
	char	*path;

	id = fork();
	if (id < 0)
		child_error(FORKFAIL);
	else if (id == 0)
	{
		if (is_builtin(cmd->argv[0], 1))
			exit(exec_builtin(cmd->original, cmd->fd[1], 0));
		path = get_path(cmd->argv[0]);
		if (!path && cmd->argv[0])
			cmd_not_found(cmd);
		else if (!path || ft_strequals(path, ""))
			exit(0);
		if (cmd->pipe_end != -1)
			close(cmd->pipe_end);
		if (dup2(cmd->fd[0], 0) == -1 || dup2(cmd->fd[1], 1) == -1)
			child_error(DUP2_ERROR);
		smart_closer(cmd->fd);
		if (execve(path, cmd->argv, cmd->env) == -1)
			child_error(EXECVE_FAIL);
	}
	else
		cmd->pid = id;
}
