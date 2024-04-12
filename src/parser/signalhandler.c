/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:32 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/12 18:43:15 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_rl_internal.h"
#include "libft.h"
#include "parser.h"

/*
	saves current running pipeline in static variable
*/
t_cmd	*save_pipeline(t_cmd *_pipline, int set)
{
	static t_cmd	*pipeline = NULL;

	if (set)
		pipeline = _pipline;
	return (pipeline);
}

int	*heredoc_stopper(int *_heredocstopper, int set)
{
	static int	*heredoc = NULL;

	if (set)
		heredoc = _heredocstopper;
	return (heredoc);
}

/*
	closes all open fds of current pipeline
*/
void	clean_pipeline(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->fd[0] != 0)
			close(cmd->fd[0]);
		if (cmd->fd[1] != 1)
			close(cmd->fd[1]);
		if (cmd->pipe_end != -1)
			close(cmd->pipe_end);
		kill(cmd->pid, SIGKILL);
		cmd = cmd->next;
	}
}

/*
	new signal handler for Ctrl+C
	needs heredoc stopping
*/
void	keyboardinterupt(int sig)
{
	t_cmd	*running;
	int		*heredoc_stop;

	(void) sig;
	running = save_pipeline(NULL, 0);
	heredoc_stop = heredoc_stopper(NULL, 0);
	if (running)
	{
		clean_pipeline(running);
		save_pipeline(NULL, 1);
	}
	else if (heredoc_stop)
	{
		close(0);
		*heredoc_stop = 1;
		heredoc_stopper(NULL, 1);
	}
	else
		ft_rl_dcl(ft_rl_getcurinput());
}
