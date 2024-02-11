/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_termutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:44:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 21:53:19 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_rl_termstate	*ft_rl_term_getstate(void)
{
	static t_rl_termstate	state;

	return (&state);
}

void	ft_rl_term_cur_updatepos(size_t promptlen)
{
	struct winsize	winsize;
	t_rl_termstate	*state;

	state = ft_rl_term_getstate();
	ioctl(1, TIOCGWINSZ, &winsize);
	state->t_rows = winsize.ws_row;
	state->t_cols = winsize.ws_col;
	ft_rl_term_cur_getpos(&state->t_row, &state->t_col, 1);
	state->i_row = state->t_row;
	state->i_col = state->t_col + promptlen;
}

void	ft_rl_term_cur_inputstart(void)
{
	t_rl_termstate	*state;

	state = ft_rl_term_getstate();
	ft_rl_term_cur_setpos(state->i_row, state->i_col);
}

void	ft_rl_term_cur_getpos(int *row, int *col, char update)
{
	size_t			i;
	t_rl_termstate	*state;
	char			buf[16];

	if (!update)
	{
		state = ft_rl_term_getstate();
		*row = state->t_row;
		*col = state->t_col;
		return ;
	}
	i = 0;
	ft_putstr_fd(TERM_STATUS, 1);
	read(0, buf, 16);
	while (buf[i] && !ft_isdigit(buf[i]))
		i++;
	*row = ft_atoi(&buf[i]);
	while (ft_isdigit(buf[i]))
		i++;
	while (buf[i] && !ft_isdigit(buf[i]))
		i++;
	*col = ft_atoi(&buf[i]);
}

void	ft_rl_term_cur_setpos(int row, int col)
{
	t_rl_termstate	*state;

	state = ft_rl_term_getstate();
	while (col > state->t_cols)
	{
		row++;
		col -= state->t_cols;
	}
	while (col < 0)
	{
		row--;
		col += state->t_cols;
	}
	ft_printf("\e[%d;%dH", row, col);
	state->t_row = row;
	state->t_col = col;
}
