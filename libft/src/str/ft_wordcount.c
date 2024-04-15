/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:05:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 23:19:59 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_wordcount.c
 */

#include "lft_is.h"
#include "lft_str.h"

/** @brief Counts all words in s
 *
 * Counts all sets of characters separated by 
 * one or more whitespace characters in s
 * @param *s String to scan
 * @retval size_t Amount of words in s
 */
size_t	ft_wordcount(const char *s)
{
	size_t	words;

	if (!s)
		return (0);
	words = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		while (*s && !ft_isspace(*s))
			s++;
		if (!ft_isspace(s[-1]))
			words++;
	}
	return (words);
}
