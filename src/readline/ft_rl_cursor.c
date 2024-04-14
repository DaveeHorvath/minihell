/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_cursor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:20:40 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/14 13:09:28 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

void	ft_rl_shiftcursor(size_t n, uint64_t direction)
{
	t_rl_cursor	*cursor;

	cursor = ft_rl_getcursor(NULL);
	while (n--)
	{
		if (direction == KEY_LEFT)
			cursor->col--;
		else
			cursor->col++;
	}
	ft_rl_updatecursor(cursor);
}

void	ft_rl_updatecursor(t_rl_cursor *cursor)
{
	if (!cursor)
		return ;
	while (cursor->col > cursor->t_cols)
	{
		cursor->row++;
		cursor->col -= cursor->t_cols;
	}
	while (cursor->col < 1)
	{
		cursor->row--;
		cursor->col += cursor->t_cols;
	}
	while (cursor->row > cursor->t_rows && cursor->p_row > 1)
	{
		ft_putstr_fd(TERM_SCROLL_UP, 1);
		cursor->p_row--;
		cursor->i_row--;
		cursor->row--;
	}
	if ((cursor->row == cursor->p_row && cursor->col < cursor->p_col)
			|| cursor->row < cursor->p_row)
	{
		cursor->row = cursor->i_row;
		cursor->col = cursor->i_col;
	}
	ft_printf("\e[%d;%dH", cursor->row, cursor->col);
}

void	ft_rl_promptcursor(t_rl_input *input)
{
	if (!input || !input->cursor)
		return ;
	input->cursor->row = input->cursor->p_row;
	input->cursor->col = input->cursor->p_col;
	ft_rl_updatecursor(input->cursor);
}

void	ft_rl_inputcursor(t_rl_input *input)
{
	if (!input || !input->cursor)
		return ;
	input->cursor->row = input->cursor->i_row;
	input->cursor->col = input->cursor->i_col;
	ft_rl_updatecursor(input->cursor);
}

void	ft_rl_resetcursor(t_rl_input *input)
{
	t_rl_word	*w;
	int16_t		n;

	if (!input || !input->cursor)
		return ;
	n = 0;
	w = input->head;
	while (w && w->i)
	{
		n += w->i;
		w = w->next;
	}
	input->cursor->row = input->cursor->i_row;
	input->cursor->col = input->cursor->i_col + n;
	ft_rl_updatecursor(input->cursor);
}
