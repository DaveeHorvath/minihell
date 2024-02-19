/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:19:08 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memmove.c
 */

#include "libft.h"

/** Copies n bytes from src to dst
 *
 * Ensures the data from src gets copied
 * to dst, even if they overlap
 * @param *dst Pointer to copy to
 * @param *src Pointer to copy from
 * @param n Amount of bytes to copy
 * @retval void * Pointer to the destination
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst || !src)
		return (dst);
	if (dst > src)
		ft_memcpy(dst, src, len);
	else
	{
		i = 0;
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}
