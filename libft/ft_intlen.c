/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:16:27 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:17 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_intlen.c
 */

#include "libft.h"

/** @brief Calculates the amount of digits in n, including '-'
 *
 * @param n Integer to count the digits of
 * @retval size_t Amount of digits in n
 */
size_t	ft_intlen(int n)
{
	int	digits;

	digits = 1;
	if (n == INT_MIN)
		n++;
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	while (n > 9)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
