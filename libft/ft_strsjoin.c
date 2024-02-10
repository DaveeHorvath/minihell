/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:01:45 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:27 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strsjoin.c
 */

#include "libft.h"

/** @brief Functions like ft_strjoin adding sep between s1 and s2
 *
 * @param *s1 String to add s2 to
 * @param *s2 String to add to s1
 * @param sep Character to insert between s1 and s2
 * @retval char * Pointer to the new string or NULL if the allocation failed
 * of s2 was NULL
 */
char	*ft_strsjoin(char const *s1, char const *s2, char sep)
{
	size_t	len1;
	size_t	len2;
	char	*out;

	if (!s2)
		return (NULL);
	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ft_pushn(2, s1, s2);
	out = ft_calloc(len1 + len2 + (sep != 0) + 1, sizeof(char));
	ft_popn(1 + (s1 != NULL));
	if (!out)
		return (NULL);
	if (s1)
		ft_strlcpy(out, s1, len1 + 1);
	if (sep)
		out[len1] = sep;
	ft_strlcpy(&out[ft_strlen(out)], s2, len2 + 1);
	return (out);
}
