/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:53:49 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 03:06:56 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_upow.c
 */

#include "lft_math.h"

/** @brief Returns n ^ p
 *
 * @param n Number to multiply
 * @param p Power to multiply to
 * @retval uint64_t Result of n ^ p
 */
uint64_t	ft_upow(const uint64_t n, int64_t p)
{
	uint64_t	out;

	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	out = 1;
	while (p--)
		out *= n;
	return (out);
}
