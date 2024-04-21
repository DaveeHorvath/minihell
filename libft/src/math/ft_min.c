/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:44:18 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 03:01:54 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_min.c
 */

#include "lft_math.h"

/** @brief Compares two values and returns the smaller one
 *
 * @param a First value
 * @param b Second value
 * @retval int64_t a if a is smaller than b, otherwise b
 */
int64_t	ft_min(const int64_t a, const int64_t b)
{
	if (a < b)
		return (a);
	return (b);
}
