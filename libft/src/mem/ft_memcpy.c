/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:03:57 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 12:50:10 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcpy.c
 */

#include "lft_mem.h"

/** @brief Copies n bytes from src to dst
 *
 * @param *dst Pointer to copy to
 * @param *src Pointer to copy from
 * @param n Amount of bytes to copy
 * @retval void * Pointer to the destination
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst || !src)
		return (dst);
	while (n > sizeof(uint64_t))
	{
		*(uint64_t *)(dst + n - sizeof(uint64_t) - 1) = \
		*(uint64_t *)(src + n - sizeof(uint64_t) - 1);
		n -= sizeof(uint64_t);
	}
	while (n > 0)
	{
		*(uint8_t *)(dst + n - 1) = \
		*(uint8_t *)(src + n - 1);
		n--;
	}
	return (dst);
}
