/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:24:54 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/27 15:51:15 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static inline void	resetcursor(t_rl_word *w);

void	ft_rl_redisplay(t_rl_input *input, t_rl_rdmode mode)
{
	t_rl_word	*w;

	if (mode == ALL)
		ft_printf("%s%s", TERM_CUR_RESET, TERM_CLEAR_END);
	else if (mode == LINE)
		ft_printf("%s%s", TERM_CUR_SOL, TERM_CLEAR_END);
	else
		ft_printf("%s", TERM_CLEAR_END);
	w = input->current;
	if (mode != CURRENT)
	{
		ft_putstr_fd(input->prompt, 1);
		w = input->head;
	}
	while (w)
	{
		if (mode != CURRENT)
			ft_putstr_fd(w->word, 1);
		else
			ft_putstr_fd(&w->word[w->i], 1);
		if (!w->next)
			break ;
		w = w->next;
	}
	resetcursor(w);
}

void	ft_rl_dbg_printinput(t_rl_input *input)
{
	size_t		node;
	t_rl_word	*w;

	node = 0;
	w = input->head;
	while (w)
	{
		ft_dprintf(2, "node %3u:\t'%-50s'", node++, w->word);
		ft_dprintf(2, "\t%u[%u]", w->len, w->i);
		if (w->wtype == SPACE)
			ft_dprintf(2, "\tSPACE\n");
		else
			ft_dprintf(2, "\tNORMAL\n");
		w = w->next;
	}
}

static inline void	resetcursor(t_rl_word *w)
{
	while (w && w->i != w->len)
	{
		ft_rl_shiftcursor(w->len - w->i, KEY_LEFT);
		w = w->prev;
	}
}
