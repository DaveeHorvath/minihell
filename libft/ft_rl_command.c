/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:32:41 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 20:18:26 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int	ft_rl_exec(t_rl_input *input, char c)
{
	if (c == KEY_RET)
	{
		ft_rl_movecursor(input, input->inputlen - input->i, KEY_RIGHT);
		ft_putchar_fd('\n', 1);
		if (input->input && !*input->input)
		{
			ft_popblk(input->input);
			input->input = NULL;
		}
		return (0);
	}
	if (c == KEY_TAB)
		ft_rl_complete(input);
	if (c == KEY_ALT)
		ft_rl_altcmd(input);
	if (c >= KEY_C_A && c <= KEY_C_Z)
		ft_rl_ctrlcmd(input, c);
	return (1);
}

int	ft_rl_iscommand(t_rl_input *input, char c)
{
	(void)input;
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
