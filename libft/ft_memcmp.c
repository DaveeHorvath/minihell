/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:51:13 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/02 21:23:19 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcmp.c
 */

#include "libft.h"

static inline void	increment(const void **s1, const void **s2, size_t isize);

/** @brief Compares the values in s1 and s2 for n bytes
 *
 * @param *s1 Pointer to the first memory area
 * @param *s2 Pointer to the second memory area
 * @param n Amount of bytes to compare
 * @retval int Difference in the values of the first unequal
 * bytes in s1 and s2, or 0 if s1 and s2 are equal for n bytes
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (n > sizeof(uint64_t) && *(uint64_t *)s1 == *(uint64_t *)s2)
	{
		increment(&s1, &s2, sizeof(uint64_t));
		n -= sizeof(uint64_t);
	}
	while (n > sizeof(uint32_t) && *(uint32_t *)s1 == *(uint32_t *)s2)
	{
		increment(&s1, &s2, sizeof(uint32_t));
		n -= sizeof(uint32_t);
	}
	while (n > sizeof(uint16_t) && *(uint16_t *)s1 == *(uint16_t *)s2)
	{
		increment(&s1, &s2, sizeof(uint16_t));
		n -= sizeof(uint16_t);
	}
	while (n > sizeof(uint8_t) && *(uint8_t *)s1 == *(uint8_t *)s2)
	{
		increment(&s1, &s2, sizeof(uint8_t));
		n -= sizeof(uint8_t);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static inline void	increment(const void **s1, const void **s2, size_t isize)
{
	*s1 += isize;
	*s2 += isize;
}
