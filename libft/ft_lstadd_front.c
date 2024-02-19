/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:19:16 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:19 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **list, t_list *node)
{
	if (!list || !node)
		return ;
	ft_lstpush(node);
	if (!*list)
	{
		node->size = ft_push(ft_calloc(1, sizeof(size_t)));
		if (!node->size)
			return ;
	}
	else
	{
		node->size = (*list)->size;
		(*list)->prev = node;
		node->next = *list;
	}
	*list = node;
	(*node->size)++;
}
