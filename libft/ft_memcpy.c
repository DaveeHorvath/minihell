/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:03:57 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 13:00:31 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcpy.c
 */

#include "libft.h"

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
	while (n > 0)
	{
		*(char *)(dst + n - 1) = *(char *)(src + n - 1);
		n--;
	}
	return (dst);
}
