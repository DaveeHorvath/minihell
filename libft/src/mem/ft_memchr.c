/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:48:36 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 05:21:28 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memchr.c
 */

#include "lft_mem.h"

static inline uint8_t	align(const uint8_t **s, uint8_t c, size_t *n);
static inline void	*findbyte(const uint8_t *s, uint8_t c, size_t n);

/** @brief Looks for c in s -> s + n
 *
 * @param *s Pointer to the start of the memory area to scan
 * @param c Value to look for
 * @param n Amount of bytes to scan
 * @retval void * Pointer to the first occurence of c, or NULL if c
 * was not found
 */
void	*ft_memchr(const void *s, uint8_t c, size_t n)
{
	const uint64_t	*wordptr;
	uint64_t		word;
	uint64_t		rep1;
	uint64_t		repc;

	if (align((const uint8_t **)&s, c, &n))
		return ((void *)s);
	wordptr = (const uint64_t *)s;
	rep1 = 0x0101010101010101;
	repc = c | (c << 8);
	repc |= repc << 16;
	repc |= repc << 32;
	while (n >= sizeof(uint64_t))
	{
		word = *wordptr ^ repc;
		if ((((word - rep1) & ~word) & (rep1 << 7)))
			break ;
		wordptr++;
		n -= sizeof(uint64_t);
	}
	return (findbyte((const uint8_t *)wordptr, (uint8_t)c, n));
}

static inline uint8_t	align(const uint8_t **s, uint8_t c, size_t *n)
{
	while (*n > 0 && *(size_t *)s % sizeof(uint64_t))
	{
		if (**s == c)
			return (1);
		(*s)++;
		(*n)--;
	}
	return (0);
}

static inline void	*findbyte(const uint8_t *s, uint8_t c, size_t n)
{
	while (n > 0)
	{
		if (*(const uint8_t *)s == (uint8_t)c)
			return ((void *)s);
		s++;
		n--;
	}
	return (NULL);
}
