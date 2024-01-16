/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getblksize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:38:15 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/09 18:42:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_getblksize.c
 */

#include "libft.h"

/** @brief Finds and returns the size of blk
 *
 * @param *blk Pointer to the block
 * @retval size_t Size of blk or 0 if blk is NULL or not registered with
 * the garbage collector
 */
size_t	ft_getblksize(void *blk)
{
	t_obj	*obj;

	obj = ft_getobj(blk);
	if (!obj)
		return (0);
	return (obj->blksize);
}
