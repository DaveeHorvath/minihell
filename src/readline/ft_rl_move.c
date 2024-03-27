/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:12:27 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/27 14:48:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

uint8_t	ft_rl_sol(t_rl_input *input)
{
	t_rl_word	*word;

	word = input->current;
	while (word)
	{
		ft_rl_shiftcursor(word->i, KEY_LEFT);
		word->i = 0;
		if (!word->prev)
			break ;
		word = word->prev;
	}
	input->current = word;
	return (1);
}

uint8_t	ft_rl_eol(t_rl_input *input)
{
	t_rl_word	*word;

	word = input->current;
	while (word)
	{
		ft_rl_shiftcursor(word->len - word->i, KEY_RIGHT);
		word->i = 0;
		if (!word->prev)
			break ;
		word = word->prev;
	}
	input->current = word;
	return (1);
}

uint8_t	ft_rl_fwd(t_rl_input *input)
{
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
	ft_dprintf(2, "bck: input->current: %p\n", input->current);
	if (input->current)
		ft_dprintf(2, "bck: current->i: %u\n", input->current->i);
	if (input->current->i > 1)
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
