/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:56:01 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 13:19:47 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strdup.c
 */

#include "libft.h"

/** @brief Allocates and returns a copy of s
 *
 * @param *s String to create a copy of
 * @retval char * Pointer to the copy or NULL if the allocation failed
 */
char	*ft_strdup(const char *s)
{
	char	*out;
	size_t	asize;

	asize = ft_strlen(s) + 1;
	ft_push((void *)s);
	out = ft_calloc(asize, sizeof(char));
	ft_pop();
	if (!out)
		return (NULL);
	ft_strlcpy(out, s, asize);
	return (out);
}
