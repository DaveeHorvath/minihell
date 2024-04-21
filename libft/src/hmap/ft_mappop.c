/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mappop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:22:56 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 07:51:34 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_gc.h"
#include "lft_hmap_internal.h"

void	ft_mappop(t_hmap_pair *pair)
{
	if (!pair)
		return ;
	ft_popblks(3, pair, pair->key, pair->value);
}

void	ft_mappop_all(t_hmap *hmap)
{
	size_t	i;

	if (!hmap)
		return ;
	i = 0;
	while (i < hmap->size)
		ft_mappop(hmap->items[i++]);
	ft_popblks(2, hmap, hmap->items);
}
