/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:10:05 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/07 14:33:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list *node)
{
	if (!node)
		return (NULL);
	ft_popblk(node);
	ft_popblk(node->blk);
	return (node);
}
