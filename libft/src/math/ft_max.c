/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:43:36 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 03:02:11 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_max.c
 */

#include "lft_math.h"

/** @brief Compares two values and returns the bigger one
 *
 * @param a First value
 * @param b Second value
 * @retval int64_t a if a is bigger than b, otherwise b
 */
int64_t	ft_max(const int64_t a, const int64_t b)
{
	if (a > b)
		return (a);
	return (b);
}
