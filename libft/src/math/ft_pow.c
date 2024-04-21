/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:40:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 03:07:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_pow.c
 */

#include "lft_math.h"

/** @brief Returns n ^ p
 *
 * @param n Number to multiply
 * @param p Power to multiply to
 * @retval int64_t Result of n ^ p
 */
int64_t	ft_pow(const int64_t n, int64_t p)
{
	int64_t	out;

	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	out = 1;
	while (p--)
		out *= n;
	return (out);
}
