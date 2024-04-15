/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:45:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 00:02:59 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstfirst.c
 */

#include "lft_lst.h"

/** @brief Returns the address of the first node of the list
 *
 * @param *list Address of a node in the list
 * @retval t_list* Address of the first node in the list,
 * or NULL if list is NULL
 */
t_list	*ft_lstfirst(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->prev)
		list = list->prev;
	return (list);
}
