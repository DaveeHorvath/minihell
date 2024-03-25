/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:38:09 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 22:58:10 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_uintlen.c
 */

#include "lft_nbr.h"

static inline uint8_t	getdiv(t_base base);

/** @brief Calculates the amount of digits in n
 *
 * @param n Unsigned integer to count the digits of
 * @retval size_t Amount of digits in n
 */
size_t	ft_uintlen(uint64_t n, t_base base)
{
	size_t	digits;
	uint8_t	div;

	digits = 1;
	div = getdiv(base);
	while (n > div - 1U)
	{
		n /= div;
		digits++;
	}
	return (digits);
}

static inline uint8_t	getdiv(t_base base)
{
	if (base == BINARY)
		return (2);
	if (base == OCTAL)
		return (8);
	if (base == DECIMAL)
		return (10);
	return (16);
}
