/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:12:27 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/18 14:06:29 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

uint8_t	ft_rl_sol(t_rl_input *input)
{
	t_rl_word	*w;

	if (!input)
		return (1);
	w = input->current;
	while (w)
	{
		w->i = 0;
		if (!w->prev)
			break ;
		w = w->prev;
	}
	input->current = w;
	ft_rl_resetcursor(input);
	return (1);
}

uint8_t	ft_rl_eol(t_rl_input *input)
{
	t_rl_word	*w;

	if (!input)
		return (1);
	w = input->current;
	while (w)
	{
		w->i = w->len;
		if (!w->next)
			break ;
		w = w->next;
	}
	input->current = w;
	ft_rl_resetcursor(input);
	return (1);
}

uint8_t	ft_rl_fwd(t_rl_input *input)
{
	if (!input || !input->current)
		return (1);
	if (input->current->i < input->current->len)
	{
		input->current->i++;
		ft_rl_shiftcursor(1, KEY_RIGHT);
	}
	else if (input->current->next)
	{
		input->current = input->current->next;
		input->current->i++;
		ft_rl_shiftcursor(1, KEY_RIGHT);
	}
	return (1);
}

uint8_t	ft_rl_bck(t_rl_input *input)
{
	if (!input || !input->current)
		return (1);
	if (input->current->i >= 1)
	{
		input->current->i--;
		ft_rl_shiftcursor(1, KEY_LEFT);
	}
	else if (input->current->prev)
	{
		input->current = input->current->prev;
		input->current->i--;
		ft_rl_shiftcursor(1, KEY_LEFT);
	}
	return (1);
}

uint8_t	ft_rl_clr(t_rl_input *input)
{
	if (!input || !input->cursor)
		return (1);
	input->cursor->p_row = 1;
	input->cursor->p_col = 1;
	input->cursor->i_row = input->cursor->p_row;
	input->cursor->i_col = input->cursor->p_col + input->plen;
	ft_rl_redisplay(input, ALL);
	return (1);
}
