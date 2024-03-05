/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:38:09 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 14:21:27 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_uintlen.c
 */

#include "libft.h"

/** @brief Calculates the amount of digits in n
 *
 * @param n Unsigned integer to count the digits of
 * @retval size_t Amount of digits in n
 */
size_t	ft_uintlen(unsigned int n)
{
	size_t	digits;

	digits = 1;
	while (n > 9)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
