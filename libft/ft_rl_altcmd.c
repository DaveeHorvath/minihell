/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_altcmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:25:02 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:23 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void	arrowcmd(t_rl_input *input)
{
	char	c;

	if (read(0, &c, 1) < 1)
		return ;
	if (c == KEY_LEFT || c == KEY_RIGHT)
		ft_rl_movecursor(input, 1, c);
	else if (c == KEY_UP)
		ft_rl_updateinput(input, ft_rl_history_next());
	else if (c == KEY_DOWN)
		ft_rl_updateinput(input, ft_rl_history_prev());
	if (c == KEY_UP || c == KEY_DOWN)
	{
		input->inputlen = ft_strlen(input->input);
		input->i = input->inputlen;
	}
}

void	ft_rl_altcmd(t_rl_input *input)
{
	char	c;

	if (read(0, &c, 1) < 1)
		return ;
	if (c == '[')
		arrowcmd(input);
	else if (c == KEY_F)
		ft_rl_nextword(input);
	else if (c == KEY_B)
		ft_rl_prevword(input);
	else if (c == '>')
		ft_rl_history_setcurrent(*ft_rl_history_gethead());
	else if (c == '<' )
		ft_rl_history_setcurrent(ft_lstlast(*ft_rl_history_getcurrent(0)));
	if (c == '>' || c == '<')
		ft_rl_updateinput(input, (*ft_rl_history_getcurrent(0))->blk);
}
