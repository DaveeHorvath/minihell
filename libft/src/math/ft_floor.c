/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 05:57:02 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 06:34:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_floor.c
 */

#include "lft_math.h"

/** @brief Rounds n to the nearest smaller whole number
 *
 * @param n Number to round
 * @retval double Nearest smaller whole number
 */
double	ft_floor(const double n)
{
	return ((double)(int64_t)n);
}
