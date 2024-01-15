/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:37:25 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 14:57:42 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atol.c
 */

#include "libft.h"

/** @brief Converts s to a long value
 *
 * @param *s String to convert
 * @retval long Converted value of s
 */
long	ft_atol(const char *s)
{
	long	out;
	int		n;

	n = 1;
	out = 0;
	while (ft_isspace(*s) != 0)
		s++;
	if (*s == '-')
		n = -n;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s) != 0)
	{
		if (out > LONG_MAX / 10 || (out == LONG_MAX / 10 && *s > '7'))
		{
			if (n < 0)
				return (0);
			return (-1);
		}
		out = out * 10 + (*s - '0');
		s++;
	}
	return (out * n);
}
