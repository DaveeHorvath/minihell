/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:26:56 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 22:32:31 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strncmp.c
 */

#include "lft_str.h"

/** @brief Compares n characters of s1 and s2
 *
 * @param *s1 First string
 * @param *s2 Second string
 * @param n Amount of characters to compare
 * @retval int Difference in values of the first different
 * characters in s1 and s2, or 0 if s1 and s2 are identical
 * for n characters
 */
int8_t	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
