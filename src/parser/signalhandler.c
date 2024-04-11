/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:32 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/11 16:35:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_rl_internal.h"
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
		ft_rl_dcl(ft_rl_getcurinput());
}
