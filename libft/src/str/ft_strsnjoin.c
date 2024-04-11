/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsnjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:34:09 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/06 12:45:03 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strsnjoin.c
 */

#include "lft_str.h"

/** Joins n strings, separated by sep
 *
 * @param n Amount of strings to join
 * @param sep Separator to use between the strings
 * @retval char* Joined string ir NULL if allocation failed or n is 0
 */
char	*ft_strsnjoin(const uint8_t sep, size_t n, ...)
{
	char	*out;
	va_list	args;

	out = NULL;
	va_start(args, n);
	while (n--)
	{
		out = ft_strsjoin(out, va_arg(args, char *), sep);
		if (!out)
			break ;
	}
	va_end(args);
	return (out);
}
