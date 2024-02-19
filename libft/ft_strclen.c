/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:41:12 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:25 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strclen.c
 */

#include "libft.h"

/** @brief Calculates the length of s until c
 *
 * @param *s String to calculate
 * @param c Character to stop at
 * @retval size_t Length of the string until c or the length of the whole
 * string if the string doesn't contain c or 0 if s is NULL
 */
size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}
