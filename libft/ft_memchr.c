/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:48:36 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memchr.c
 */

#include "libft.h"

/** @brief Looks for c in s -> s + n
 *
 * @param *s Pointer to the start of the memory area to scan
 * @param c Value to look for
 * @param n Amount of bytes to scan
 * @retval void * Pointer to the first occurence of c, or NULL if c
 * was not found
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
		n--;
	}
	return (NULL);
}
