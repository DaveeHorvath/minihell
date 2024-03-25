/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:34:07 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 22:33:11 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strnstr.c
 */

#include "lft_str.h"

/** @brief Finds needle in haystack
 *
 * Looks for the substring needle in the string haystack, searching at most
 * n characters
 * @param *haystack String to look in
 * @param *needle String to look for
 * @param n Amount of characters to search
 * @retval char * Pointer to the start of needle in haystack if found,
 * Pointer to haystack if needle is NULL
 * or NULL if needle was not found or if haystack is NULL
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (!haystack)
		return (NULL);
	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < n)
		{
			if (!(haystack[i + j]))
				break ;
			j++;
		}
		if (!(needle[j]))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
