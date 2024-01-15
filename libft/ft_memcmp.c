/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:51:13 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 13:45:59 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcmp.c
 */

#include "libft.h"

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
	if (n == 0)
		return (0);
	while (*(char *)s1 == *(char *)s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
