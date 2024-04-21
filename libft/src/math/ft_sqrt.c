/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 05:08:17 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 06:33:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_sqrt.c
 */

#include "lft_math.h"

static inline double	_estimate(const double n);

/** @crief Calculates the square root of n
 *
 * @param n Number to get square root of
 * @retval double Square root of n,
 * or 0.0 if n <= 0.0
 */
double	ft_sqrt(const double n)
{
	double	e;
	size_t	i;

	if (n <= 0.0)
		return (0.0);
	e = _estimate(n);
	i = 0;
	while (i++ < 5)
		e = 0.5 * (e + (n / e));
	return (e);
}

static inline double	_estimate(const double n)
{
	double	d1;
	double	d2;
	double	i;

	i = 1;
	d1 = i * i;
	if (n < d1)
		return (i);
	i++;
	d2 = i * i;
	while (n > d2)
	{
		i++;
		d1 = d2;
		d2 = i * i;
	}
	if (d2 - n > n - d1)
		return (i - 1);
	return (i);
}
