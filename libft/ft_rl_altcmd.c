/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_altcmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:25:02 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/09 22:25:32 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	arrowcmd(size_t *i, char **line)
{
	char	c;

	if (read(0, &c, 1) < 1)
		return ;
	if (c == KEY_LEFT || c == KEY_RIGHT)
		ft_rl_movecursor(i, ft_strlen(*line), c);
	else if (c == KEY_UP)
		*line = ft_rl_history_next();
	else if (c == KEY_DOWN)
		*line = ft_rl_history_prev();
	if (c == KEY_UP || c == KEY_DOWN)
		*i = ft_strlen(*line);
}

void	ft_rl_altcmd(size_t *i, char *p, char **line)
{
	char	c;

	if (read(0, &c, 1) < 1)
		return ;
	if (c == '[')
		arrowcmd(i, line);
	else if (c == KEY_F)
		ft_rl_nextword(i, *line, ft_strlen(p));
	else if (c == KEY_B)
		ft_rl_lastword(i, *line, ft_strlen(p));
	else if (c == '>')
		ft_rl_history_setcurrent(*ft_rl_history_gethead());
	else if (c == '<' )
		ft_rl_history_setcurrent(ft_lstlast(*ft_rl_history_getcurrent(0)));
	if (c == '>' || c == '<')
	{
		*line = (*ft_rl_history_getcurrent(0))->blk;
		*i = ft_strlen(*line);
	}
}
