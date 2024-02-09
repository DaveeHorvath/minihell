/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:23:00 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/09 23:21:03 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strrchr.c
 */

#include "libft.h"

/** @brief Finds the last occurence of c in s
 *
 * @param *s String to look for c in
 * @param c Character to look for
 * @retval char * Pointer to the last occurence of c or
 * NULL if c was not found
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!(char)c)
		return ((char *)&s[i]);
	while (i)
	{
		if (s[i - 1] == (char)c)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (NULL);
}
