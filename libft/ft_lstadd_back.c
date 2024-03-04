/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:29:29 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/26 12:33:39 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_back.c
 */

#include "libft.h"

/** @brief Adds a new node to the back of a list
 *
 * Adds a new node to the list, initializing the list size
 * if the list is empty
 * @param **list Address of the head pointer to the list
 * @param *node Address of the new node
 */
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
