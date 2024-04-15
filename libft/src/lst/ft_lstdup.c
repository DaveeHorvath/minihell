/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:21:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/21 07:36:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstdup.c
 */

#include "lft_gc.h"
#include "lft_lst.h"
#include "lft_mem.h"

static inline void	*dupblk(void *blk);

/** @brief Creates a duplicate of a node and its content
 *
 * @param *node Address of the node
 * @retval t_list* Address of the duplicated node,
 * or NULL if an allocation fails
 */
t_list	*ft_lstdup(t_list *node)
{
	t_list	*out;

	ft_lstpush(node);
	out = ft_push(ft_calloc(1, sizeof(*out)));
	if (!out)
	{
		ft_lstpop(node);
		return (NULL);
	}
	out->blk = dupblk(node->blk);
	ft_lstpop(node);
	ft_popblk(out);
	if (!out->blk && node->blk)
		return (NULL);
	return (out);
}

static inline void	*dupblk(void *blk)
{
	void	*out;
	size_t	asize;

	asize = ft_getblksize(blk);
	if (!blk || !asize)
		return (NULL);
	out = ft_alloc(asize);
	if (!out)
		return (NULL);
	ft_memcpy(out, blk, asize);
	return (out);
}
