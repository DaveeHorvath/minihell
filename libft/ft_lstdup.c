/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:21:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/02 06:23:09 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *node)
{
	t_list	*out;

	ft_lstpush(node);
	out = ft_calloc(1, sizeof(t_list));
	ft_lstpop(node);
	if (!out)
		return (NULL);
	out->blk = node->blk;
	out->size = node->size;
	return (out);
}
