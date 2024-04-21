/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 06:41:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 06:46:25 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isprime.c
 */

#include "lft_is.h"
#include "lft_math.h"

/** @brief Checks if n is a prime number
 *
 * @param n Number to check
 * @retval uint8_t 1 if n is prime,
 * 0 if not or undefined
 */
uint8_t	ft_isprime(const uint64_t n)
{
	size_t	i;

	if (n < 2 || (n % 2) == 0)
		return (0);
	if (n < 4)
		return (1);
	i = 3;
	while (i < ft_floor(ft_sqrt(n)))
	{
		if ((n % i) == 0)
			return (0);
		i += 2;
	}
	return (1);
}
