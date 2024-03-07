/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:04:35 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 11:48:49 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_free.c
 */

#include "libft.h"

/** @brief Frees the allocated memory at ptr
 *
 * Looks for an object pointing to ptr before freeing it. If an object 
 * pointing to ptr was found, sets the objects pointer to ptr to NULL 
 * to prevent the garbage collector from trying to double free ptr.
 * @param ptr Pointer to the block to free
 */
void	ft_free(void *ptr)
{
	t_obj	*obj;

	obj = ft_getvm()->head;
	while (obj)
	{
		if (obj->blk == ptr)
			break ;
		obj = obj->next;
	}
	if (obj)
		obj->blk = NULL;
	free(ptr);
}
