/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:21:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/26 12:51:27 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstdup.c
 */

#include "libft.h"

/** @brief Creates a duplicate of a node and its content
 *
 * @param *node Address of the node
 * @retval t_list* Address of the duplicated node,
 * or NULL if an allocation fails
 */
t_list	*ft_lstdup(t_list *node)
{
	t_list	*out;
	size_t	asize;

	ft_lstpush(node);
	out = ft_push(ft_calloc(1, sizeof(t_list)));
	ft_lstpop(node);
	if (!out)
		return (NULL);
	if (node->blk)
	{
		asize = ft_getblksize(node->blk);
		out->blk = ft_alloc(asize);
		ft_pop();
		if (!out->blk)
			return (NULL);
		ft_memcpy(out->blk, node->blk, asize);
		out->size = node->size;
	}
	else
		out->blk = NULL;
	return (out);
}
