/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:00:57 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/04 15:55:09 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strtrim.c
 */

#include "libft.h"

/** @brief Creates a copy of s1, with all of the characters in set
 * removed from the start and end of s1
 *
 * @param *s1 String to trim
 * @param *set Characters to trim from s1
 * @retval char * Pointer to the new string or NULL if the allocation failed
 * or one of the parameters was NULL
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	if (!(*s1))
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_contains(set, s1[i]) == 1)
		i++;
	while (ft_contains(set, s1[j]) == 1 && j > i)
		j--;
	return (ft_substr(s1, i, j + 1 - i));
}
