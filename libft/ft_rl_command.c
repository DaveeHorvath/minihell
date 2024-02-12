/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:32:41 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/12 16:50:08 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int	ft_rl_exec(t_rl_input *input, char c, char redisplay)
{
	if (c == KEY_RET || (c == KEY_C_D && !input->inputlen))
	{
		if (c == KEY_RET)
		{
			if (redisplay)
				ft_rl_redisplay(input);
			ft_rl_movecursor(input, input->inputlen - input->i, KEY_RIGHT);
			ft_putchar_fd('\n', 1);
		}
		if (input->input && ((c == KEY_RET && !*input->input) || c == KEY_C_D))
		{
			ft_popblk(input->input);
			input->input = NULL;
		}
		return (0);
	}
	if (c == KEY_TAB)
		return (ft_rl_complete(input));
	if (c == KEY_ALT)
		ft_rl_altcmd(input, redisplay);
	else if (c >= KEY_C_A && c <= KEY_C_Z)
		ft_rl_ctrlcmd(input, c, redisplay);
	return (1);
}

int	ft_rl_iscommand(char c)
{
	if (c == KEY_RET)
		return (1);
	if (c == KEY_TAB)
		return (1);
	if (c == KEY_ALT)
		return (1);
	if (c >= KEY_C_A && c <= KEY_C_Z)
		return (1);
	return (0);
}
