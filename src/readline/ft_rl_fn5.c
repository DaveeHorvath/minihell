/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_fn5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:20:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/11 16:27:22 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

uint8_t	ft_rl_hlc(t_rl_input *input)
{
	uint64_t			key;
	static const char	carr[8][6] = {SGR_FG0, SGR_FG1, SGR_FG2, SGR_FG3,
		SGR_FG4, SGR_FG5, SGR_FG6, SGR_FG7};

	key = 0;
	if (read(0, &key, sizeof(key)) < 0)
		return (-1);
	if (key - KEY_NUM_0 < 10)
		ft_rl_sethlcolor(carr[key - KEY_NUM_0]);
	return (1);
	(void)input;
}

uint8_t	ft_rl_dcl(t_rl_input *input)
{
	ft_rl_popwords(input->head);
	input->current = NULL;
	input->head = NULL;
	input->cursor->i_row++;
	ft_rl_inputcursor(input);
	ft_rl_redisplay(input, PROMPT);
	return (1);
}