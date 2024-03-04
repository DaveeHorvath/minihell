/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrmnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:47:17 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/26 12:42:11 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstrmnode.c
 */

#include "libft.h"

/** @brief Removes a node from a list
 *
 * @param **list Address of the head pointer of the list
 * @param *node Address of the node
 */
void	ft_lstrmnode(t_list **list, t_list *node)
{
	if (!list || !node)
		return ;
	if (node->next)
		node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	ft_lstpop(node);
}
