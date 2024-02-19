/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:41:02 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:27 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_substr.c
 */

#include "libft.h"

/** @brief Allocates and returns a substring of s of len characters
 * starting at index start
 *
 * @param *s String to create substring from
 * @param start Index to start substring from
 * @param len Length of the substring
 * @retval char * Pointer to the substring or NULL if the allocation failed
 * or if s is NULL
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	slen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	slen = ft_strlen(&s[start]);
	if (len > slen)
		len = slen;
	ft_push((void *)s);
	out = ft_calloc(len + 1, sizeof(char));
	ft_pop();
	if (!out)
		return (NULL);
	ft_strlcpy(out, &s[start], len + 1);
	return (out);
}
