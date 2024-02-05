/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrmnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:47:17 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/01 21:50:42 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
