/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:00:57 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 05:22:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strtrim.c
 */

#include "lft_str.h"

/** @brief Creates a copy of s1, with all of the characters in set
 * removed from the start and end of s1
 *
 * @param *s1 String to trim
 * @param *set Characters to trim from s1
 * @retval char * Pointer to the new string or NULL if the allocation failed
 * or one of the parameters was NULL
 */
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	if (!(*s1))
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[j]) && j > i)
		j--;
	return (ft_substr(s1, i, j + 1 - i));
}
