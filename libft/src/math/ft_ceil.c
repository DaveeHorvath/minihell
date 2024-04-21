/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 06:18:55 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 06:35:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_ceil.c
 */

#include "lft_math.h"

/** @brief Rounds n to the nearest bigger whole number
 *
 * @param n Number to round
 * @retval double Nearest bigger whole number
 */
double	ft_ceil(const double n)
{
	if (n == (double)(int64_t)n)
		return (n);
	return ((double)(int64_t)n + 1.0);
}
