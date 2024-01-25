/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:47:57 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/24 15:14:11 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*ft_substr(char *s, int start, int len);

int	exec_pipeline(char *s)
{
	t_list	*commands;
	t_cmd	*to_exec;
	int		prev_out;
	int		exitcode;
	int		fds[2];

	commands = parse_pipeline(s);
	prev_out = -1;
	while (commands)
	{
		get_fds(commands, &prev_out, (int *)fds);
		make_cmd(commands, to_exec, (int *)fds);
		commands = commands->next;
	}
	while (to_exec)
	{
		waitpid(to_exec, &exitcode, WNOHANG);
		if (!to_exec->next && WIFEXITED(exitcode))
		{
			clean();
			return (exitcode);
		}
		to_exec = to_exec->next;
	}
	return (0);
}
