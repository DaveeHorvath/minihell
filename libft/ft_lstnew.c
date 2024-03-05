/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:05:15 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/26 12:30:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstnew.c
 */

#include "libft.h"

/** @brief Allocates a new node
 *
 * @param *blk Address of block to be stored in the nodes blk field
 * @retval t_list* Pointer to the new node, or NULL if the allocation failed
 */
t_list	*ft_lstnew(void *blk)
{
	t_list	*out;

	ft_push(blk);
	out = ft_calloc(1, sizeof(t_list));
	if (blk)
		ft_pop();
	if (!out)
		return (NULL);
	out->blk = blk;
	return (out);
}
