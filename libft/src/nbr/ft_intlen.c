/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:16:27 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 22:58:02 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_intlen.c
 */

#include "lft_nbr.h"

static inline int8_t	getdiv(t_base base);

/** @brief Calculates the amount of digits in n, including '-'
 *
 * @param n Integer to count the digits of
 * @param base Base to count in
 * @retval size_t Amount of digits in n
 */
size_t	ft_intlen(int64_t n, t_base base)
{
	size_t	digits;
	int8_t	div;

	digits = 1;
	div = getdiv(base);
	if (n == INT64_MIN)
		n++;
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	while (n > div - 1)
	{
		n /= div;
		digits++;
	}
	return (digits);
}

static inline int8_t	getdiv(t_base base)
{
	if (base == BINARY)
		return (2);
	if (base == OCTAL)
		return (8);
	if (base == DECIMAL)
		return (10);
	return (16);
}
