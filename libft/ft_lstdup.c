/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:21:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:19 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *node)
{
	t_list	*out;
	size_t	asize;

	asize = ft_getblksize(node->blk);
	ft_lstpush(node);
	out = ft_push(ft_calloc(1, sizeof(t_list)));
	ft_lstpop(node);
	if (!out)
		return (NULL);
	out->blk = ft_alloc(asize);
	ft_memcpy(out->blk, node->blk, asize);
	out->size = node->size;
	ft_pop();
	return (out);
}
