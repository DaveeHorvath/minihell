/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:32 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/03 17:16:11 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "parser.h"

int	g_has_recieved = 0;

t_cmd	*save_pipeline(t_cmd *_pipline)
{
	static t_cmd	*pipeline;

	if (_pipline)
		pipeline = _pipline;
	else
		return (pipeline);
	return (NULL);
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
	g_has_recieved = 0;
	clean_pipeline(save_pipeline(NULL));
}
