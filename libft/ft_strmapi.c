/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:57:22 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 15:02:56 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strmapi.c
 */

#include "libft.h"

/** @brief Allocates and returns a duplicate of s
 * with f applied to all characters
 *
 * @param *s String to duplicate
 * @param *f Pointer to the function to apply
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	size_t	i;

	if (!s)
		return (NULL);
	ft_push((void *)s);
	out = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	ft_pop();
	if (!out)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = f(i, s[i]);
		i++;
	}
	return (out);
}
