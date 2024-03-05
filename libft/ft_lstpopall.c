/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:50:59 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/26 12:36:49 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstpopall.c
 */

#include "libft.h"

/** @brief Pops all nodes in the list
 *
 * @param *list Address of the first node of the list
 */
void	ft_lstpopall(t_list *list)
{
	while (list)
	{
		ft_lstpop(list);
		list = list->next;
	}
}
