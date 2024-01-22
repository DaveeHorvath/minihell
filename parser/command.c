/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:33:29 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/22 23:38:52 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	make_cmd(t_list *toparse, t_cmd *commands, int *fds)
{
	extern char	**environ;

	commands->argv = get_arguments(toparse);
	commands->env = environ;
	commands->pid = call_cmd(commands, fds);
}

char	**get_arguments(char *toparse)
{
	return (0);
}

pid_t	call_cmd(t_cmd *cmd, int *fds)
{
	pid_t	pid;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
		if (dup2(1, fds[1]) == -1 || dup2(0, fds[0]) == -1)
			child_error();
		path = get_path(cmd->argv[0]);
		if (!path)
			cmd_not_found();
		execve(path, &(cmd->argv[1]), cmd->env);
	}
	else if (pid != -1)
		return (pid);
	else
		child_error();
}