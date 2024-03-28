/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_fn2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:41:48 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/28 02:37:43 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

uint8_t		ft_rl_fwd_w(t_rl_input *input)
{
	t_rl_word	*w;

	if (!input->current)
		return (1);
	w = input->current;
	w->i = w->len;
	if (w->next)
	{
		w = w->next;
		if (w->wtype == SPACE)
		{
			w->i = w->len;
			if (w->next)
				w = w->next;
		}
	}
	input->current = w;
	ft_rl_resetcursor(input);
	return (1);
}

uint8_t		ft_rl_bck_w(t_rl_input *input)
{
	t_rl_word	*w;

	if (!input->current)
		return (1);
	w = input->current;
	if (w->i > 0)
		w->i = 0;
	else if (w->prev)
		w = w->prev;
	if (w->wtype == SPACE && w->prev)
		w = w->prev;
	if (w->i > 0)
		w->i = 0;
	input->current = w;
	ft_rl_resetcursor(input);
	return (1);
}

uint8_t	ft_rl_acl(t_rl_input *input)
{
	ft_rl_eol(input);
	ft_putchar_fd('\n', 1);
	return (0);
}

uint8_t	ft_rl_eof(t_rl_input *input)
{
	if (input->head)
		return (1);
	ft_putchar_fd('\n', 1);
	return (0);
}
