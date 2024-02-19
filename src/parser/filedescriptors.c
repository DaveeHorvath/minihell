/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filedescriptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:33:56 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/22 23:41:58 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_fds(char *to_parse, int fds[2])
{
	return ;
}

void	get_fds(t_list *toparse, int *prev_out, int *fds)
{
	int		pipefds[2];

	fds[0] = -1;
	fds[1] = -1;
	parse_fds(toparse->content, fds);
	if (toparse->next)
	{
		if (pipe(pipefds) == -1)
			return ;
	}
	if (fds[0] == -1)
		fds[0] = *prev_out;
	if (fds[1] == -1)
	{
		*prev_out = pipefds[0];
		fds[1] = pipefds[1];
	}
}
