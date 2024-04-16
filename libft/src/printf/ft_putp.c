/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:08:43 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 16:14:40 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putp.c
 */

#include "libft.h"

/** @brief Prints the address of a pointer according to the flags
 *
 * @param args va_list containing the pointers address
 * @param *flags Pointer to the output flag array
 * @retval int Amount of characters printed or -1 if an error occurred
 */
int	ft_putp(va_list args, int *flags)
{
	int	rv1;
	int	rv2;

	rv1 = ft_putstr_fd("0x", ft_pfgetfd());
	rv2 = ft_putx(args, flags, 'x');
	if (rv1 < 0 || rv2 < 0)
		return (-1);
	return (0);
}
