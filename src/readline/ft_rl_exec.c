/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:28:40 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/26 12:48:42 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rl_map_internal.h"

uint8_t	ft_rl_execmap(t_rl_input *input, uint64_t key)
{
	t_list	*keymaps;

	keymaps = *ft_rl_getkeymaps();
	while (keymaps)
	{
		if (((t_rl_map *)keymaps->blk)->key == key)
			return (((t_rl_map *)keymaps->blk)->f(input));
		keymaps = keymaps->next;
	}
	return (1);
}
