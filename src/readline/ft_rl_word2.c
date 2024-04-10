/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_word2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:16:32 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/10 12:22:39 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

void	ft_rl_replaceword(t_rl_input *input, t_rl_word *w)
{
	if (!input || !w)
		return ;
	if (!input->head)
		ft_rl_insertword(input, w);
	else
	{
		if (input->current->prev)
			input->current->prev->next = w;
		if (input->current->next)
			input->current->next->prev = w;
		ft_popblks(2, input->current, input->current->word);
	}
}
