/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 06:23:36 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 06:35:26 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_round.c
 */

#include "lft_math.h"

/** @brief Rounds n to the nearest whole number
 *
 * @param n Number to round
 * @retval double Nearest whole number
 */
double	ft_round(const double n)
{
	double	rf;

	if (n == (double)(int64_t)n)
		return (n);
	rf = 0.5;
	if (n < 0.0)
		rf = -0.5;
	return ((double)(int64_t)(n + rf));
}
