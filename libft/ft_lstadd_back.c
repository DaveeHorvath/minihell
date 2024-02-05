/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:29:29 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/03 20:57:22 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *node)
{
	t_list	*last;

	if (!list || !node)
		return ;
	ft_lstpush(node);
	last = ft_lstlast(*list);
	if (!last)
	{
		node->size = ft_push(ft_calloc(1, sizeof(size_t)));
		if (!node->size)
			return ;
		*list = node;
	}
	else
	{
		node->size = last->size;
		node->prev = last;
		last->next = node;
	}
	(*node->size)++;
}
