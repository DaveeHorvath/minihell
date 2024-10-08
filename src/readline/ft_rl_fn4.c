/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_fn4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:15:51 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/18 14:08:12 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

uint8_t	ft_rl_upw(t_rl_input *input)
{
	t_rl_word	*w;

	if (!input)
		return (1);
	w = input->current;
	if (!w || (w->wtype == SPACE && !w->next))
		return (1);
	if (w->i == w->len && w->next)
		w = w->next;
	if (w->wtype == SPACE)
		ft_rl_fwd_w(input);
	w = input->current;
	ft_strupper(&w->word[w->i]);
	w->i = w->len;
	ft_rl_redisplay(input, LINE);
	return (1);
}

uint8_t	ft_rl_dnw(t_rl_input *input)
{
	t_rl_word	*w;

	if (!input)
		return (1);
	w = input->current;
	if (!w || (w->wtype == SPACE && !w->next))
		return (1);
	if (w->i == w->len && w->next)
		w = w->next;
	if (w->wtype == SPACE)
		ft_rl_fwd_w(input);
	w = input->current;
	ft_strlower(&w->word[w->i]);
	w->i = w->len;
	ft_rl_redisplay(input, LINE);
	return (1);
}

uint8_t	ft_rl_caw(t_rl_input *input)
{
	t_rl_word	*w;

	if (!input)
		return (1);
	w = input->current;
	if (!w || (w->wtype == SPACE && !w->next))
		return (1);
	if (w->i == w->len && w->next)
		w = w->next;
	if (w->wtype == SPACE)
		ft_rl_fwd_w(input);
	w = input->current;
	w->word[w->i] = ft_toupper(w->word[w->i]);
	if (w->i < w->len)
		ft_strlower(&w->word[w->i + 1]);
	w->i = w->len;
	ft_rl_redisplay(input, LINE);
	return (1);
}

uint8_t	ft_rl_cmp(t_rl_input *input)
{
	if (!input)
		return (1);
	return (ft_rl_complete(input));
}

uint8_t	ft_rl_mta(t_rl_input *input)
{
	uint64_t	key;

	if (!input)
		return (1);
	key = 0;
	read(0, &key, sizeof(key));
	if (input->sigexit)
		return (0);
	key = (key << 8) + 0x1BULL;
	if (ft_rl_ismapped(key))
		return (ft_rl_execmap(input, key));
	return (1);
}
