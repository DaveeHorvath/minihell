/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:48:55 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/06 13:04:15 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_arrdup.c
 */

#include "lft_gc.h"
#include "lft_mem.h"

/** @brief Allocates a duplicate of arr
 *
 * @param arr Pointer to the start of the arr
 * @param size Size of the arr
 * @retval void* Pointer to the duplcated array or
 * NULL if allocation failed or size is 0
 */
void	*ft_arrdup(const void *arr, const size_t size)
{
	void	*out;

	if (!size)
		return (0);
	ft_push(arr);
	out = ft_memcpy(ft_alloc(size), arr, size);
	ft_popblk(arr);
	return (out);
}
