/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:28:36 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/06 12:38:15 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strnjoin.c
 */

#include "lft_str.h"

/** Joins n strings together
 *
 * @param n Amount of strings to join
 * @@retval char* Joined string or NULL if allocation failed or n is 0
 */
char	*ft_strnjoin(size_t n, ...)
{
	char	*out;
	va_list	args;

	out = NULL;
	va_start(args, n);
	while (n--)
	{
		out = ft_strjoin(out, va_arg(args, char *));
		if (!out)
			break ;
	}
	va_end(args);
	return (out);
}
