/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:24:54 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/28 15:36:31 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

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
		w = w->next;
	}
	ft_rl_resetcursor(input);
}
