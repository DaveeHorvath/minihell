/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_term_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:17:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/14 14:36:35 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline void	initcursor(t_rl_cursor *cursor, size_t plen);

t_rl_cursor	*ft_rl_getcursor(t_rl_input *input)
{
	static t_rl_cursor	cursor;

	if (input)
		initcursor(&cursor, input->plen);
	return (&cursor);
}

void	ft_rl_getcurpos(int16_t *row, int16_t *col)
{
	size_t	i;
	char	buf[17];

	i = 0;
	ft_bzero(buf, 17);
	ft_putstr_fd(TERM_STATUS, 1);
	read(0, buf, 16);
	while (buf[i] && !ft_isdigit(buf[i]))
		i++;
	if (row)
		*row = ft_atoi16(&buf[i]);
	while (ft_isdigit(buf[i++]))
		;
	while (buf[i] && !ft_isdigit(buf[i]))
		i++;
	if (col)
		*col = ft_atoi16(&buf[i]);
}

void	ft_rl_term_scroll(uint64_t dir, t_rl_cursor *cursor)
{
	if (dir == KEY_UP)
	{
		ft_putstr_fd(TERM_SCROLL_UP, 1);
		cursor->p_row--;
		cursor->i_row--;
		cursor->row--;
	}
	else
	{
		ft_putstr_fd(TERM_SCROLL_DOWN, 1);
		cursor->p_row++;
		cursor->i_row++;
		cursor->row++;
	}
}

static inline void	initcursor(t_rl_cursor *cursor, size_t plen)
{
	if (!cursor)
		return ;
	ft_rl_getcurpos(&cursor->p_row, &cursor->p_col);
	ft_printf("\e[99999;99999H");
	ft_rl_getcurpos(&cursor->t_rows, &cursor->t_cols);
	cursor->row = cursor->p_row;
	cursor->col = cursor->p_col;
	cursor->i_row = cursor->p_row;
	cursor->i_col = cursor->p_col + plen;
	while (cursor->i_col > cursor->t_cols)
	{
		cursor->i_row++;
		cursor->i_col -= cursor->t_cols;
	}
	ft_printf("\e[%d;%dH", cursor->p_row, cursor->p_col);
}
