/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:56:02 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 03:01:35 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_umin.c
 */

#include "lft_math.h"

/** @brief Compares two values, and returns the smaller one
 *
 * @param a First value
 * @param b Second value
 * @retval uint64_t a if a is smaller than b, otherwise b
 */
uint64_t	ft_umin(const uint64_t a, const uint64_t b)
{
	if (a < b)
		return (a);
	return (b);
}
