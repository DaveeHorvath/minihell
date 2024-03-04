/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:54:19 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 11:54:10 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_hexlen.c
 */

#include "libft.h"

/** @brief Calculates the amount of digits in n, treating it as a hex value
 *
 * @param n Unsigned long to count the digits of
 * @retval size_t Amount of digits in n
 */
size_t	ft_hexlen(unsigned long n)
{
	size_t	digits;

	digits = 1;
	while (n > 15)
	{
		n /= 16;
		digits++;
	}
	return (digits);
}
