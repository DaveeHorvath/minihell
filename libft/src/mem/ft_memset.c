/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:33:24 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 12:54:26 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memset.c
 */

#include "lft_mem.h"

/** @brief Sets n bytes to c, starting from b
 *
 * @param *b Pointer to the start of the memory area
 * @param c value to set for each byte
 * @param n Amount of bytes to set
 * @retval void * Pointer to the start of the memory area
 */
void	*ft_memset(void *s, uint8_t c, size_t n)
{
	uint64_t	c8;
	size_t		n8;
	void		*out;

	out = s;
	if (n >= sizeof(uint64_t))
	{
		c8 = c | (c << 8);
		c8 |= c8 << 16;
		c8 |= c8 << 32;
		while (n-- % sizeof(uint64_t))
			*(char *)s++ = c;
		n8 = n / sizeof(uint64_t);
		while (n8)
		{
			*((uint64_t *)s) = c8;
			s += sizeof(uint64_t);
			n8--;
		}
		n %= sizeof(uint64_t);
	}
	while (n--)
		*(char *)s++ = c;
	return (out);
}
