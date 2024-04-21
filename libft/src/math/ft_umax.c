/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:55:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 03:03:01 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_umax.c
 */

#include "lft_math.h"

/** @brief Compares two values, and returns the bigger one
 *
 * @param a First value
 * @param b Second value
 * @retval uint64_t a if a is bigger than b, otherwise b
 */
uint64_t	ft_umax(const uint64_t a, const uint64_t b)
{
	if (a > b)
		return (a);
	return (b);
}
