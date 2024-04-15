/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_keymap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:28:01 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/28 15:47:42 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

uint8_t	ft_rl_ismapped(uint64_t key)
{
	t_list	*keymaps;

	keymaps = *ft_rl_getkeymaps();
	while (keymaps)
	{
		if (((t_rl_map *)keymaps->blk)->key == key)
			return (1);
		keymaps = keymaps->next;
	}
	return (0);
}

t_rl_fn	ft_rl_getmap(uint64_t key)
{
	t_list	*keymaps;

	keymaps = *ft_rl_getkeymaps();
	while (keymaps)
	{
		if (((t_rl_map *)keymaps->blk)->key == key)
			return (((t_rl_map *)keymaps->blk)->f);
		keymaps = keymaps->next;
	}
	return (NULL);
}
