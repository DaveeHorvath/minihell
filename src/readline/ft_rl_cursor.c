/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_cursor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:25:21 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/18 20:07:46 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_rl_movecursor(t_rl_input *input, size_t n, char direction)
{
	int		row;
	int		col;

	if ((direction == KEY_LEFT && !input->i)
		|| (direction == KEY_RIGHT && input->i == input->inputlen))
		return ;
	ft_rl_term_cur_getpos(&row, &col, 0);
	if (direction == KEY_RIGHT)
	{
		while (n-- && input->i < input->inputlen)
		{
			input->i++;
			col++;
		}
	}
	else
	{
		while (n-- && input->i > 0)
		{
			input->i--;
			col--;
		}
	}
	ft_rl_term_cur_setpos(row, col);
}

void	ft_rl_resetscreen(t_rl_input *input)
{
	int	row;
	int	col;

	ft_putstr_fd(TERM_CLEAR_SCREEN, 1);
	ft_rl_term_cur_setpos(1, 1);
	ft_rl_term_cur_updatepos(input->promptlen);
	ft_rl_term_cur_getpos(&row, &col, 0);
	ft_putstr_fd(input->prompt, 1);
	if (input->input)
		ft_putstr_fd(input->input, 1);
	ft_rl_term_cur_setpos(row, col + input->promptlen + input->i);
}
