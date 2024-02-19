/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:33:24 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:28 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *s)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		while (*s && !ft_isspace(*s))
			s++;
		if (*(s - 1))
			words++;
	}
	return (words);
}
