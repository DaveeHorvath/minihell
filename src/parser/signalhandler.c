/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:32 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/06 15:03:41 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "parser.h"

int	g_has_recieved = 0;

t_cmd	*save_pipeline(t_cmd *_pipline, int set)
{
	static t_cmd	*pipeline = NULL;

	if (set)
		pipeline = _pipline;
	return (pipeline);
}

void	clean_pipeline(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->fd[0] != 0)
			close(cmd->fd[0]);
		if (cmd->fd[1] != 1)
			close(cmd->fd[1]);
		kill(cmd->pid, SIGKILL);
		cmd = cmd->next;
	}
}

void	keyboardinterupt(int sig)
{
	t_cmd	*running;

	(void) sig;
	running = save_pipeline(NULL, 0);
	if (running)
	{
		clean_pipeline(running);
		save_pipeline(NULL, 1);
	}
	else
	{
		ft_dprintf(2, "\nkeyboardinterupt without running");
	}
}
