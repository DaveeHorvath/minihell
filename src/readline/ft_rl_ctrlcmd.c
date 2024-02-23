/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_ctrlcmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:25:37 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/19 21:58:03 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int	ft_rl_ctrlcmd(t_rl_input *input, char c, char redisplay)
{
	if (c == KEY_C_A)
		ft_rl_movecursor(input, input->i, KEY_LEFT);
	else if (c == KEY_C_E)
		ft_rl_movecursor(input, input->inputlen - input->i, KEY_RIGHT);
	else if (c == KEY_C_F)
		ft_rl_movecursor(input, 1, KEY_RIGHT);
	else if (c == KEY_C_B)
		ft_rl_movecursor(input, 1, KEY_LEFT);
	else if (c == KEY_C_L)
		ft_rl_resetscreen(input);
	else if (c == KEY_C_P)
		ft_rl_updateinput(input, ft_rl_history_next());
	else if (c == KEY_C_N)
		ft_rl_updateinput(input, ft_rl_history_prev());
	else if (c == KEY_C_R)
		return (ft_rl_history_search(input, KEY_UP));
	if (redisplay)
		ft_rl_redisplay(input);
	return (0);
}
