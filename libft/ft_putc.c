/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:13:44 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putc.c
 */

#include "libft.h"

/** @brief Prints the character specified by the arguments
 *
 * Prints % if format is %, otherwise prints the character returned from va_arg.
 * Prints left and right padding depending on the flags.
 * @param args va_list containing the character to be printed
 * @param *flags Pointer to the output flag array
 * @param format Character specifying whether to print a % (%) or a character
 * from args (c)
 * @retval int Amount of characters printed or -1 if an error occurred
 */
int	ft_putc(va_list args, int *flags, char format)
{
	char	c;
	int		rv1;
	int		rv2;

	rv1 = 0;
	if (format == '%')
		c = '%';
	else
		c = va_arg(args, int);
	if (flags[0] == 0)
		rv1 = putpadding(flags[2] - 1, ' ', &flags[0], flags);
	if (rv1 < 0)
		return (-1);
	rv2 = ft_putchar_fd(c, ft_pfgetfd());
	if (rv2 < 0)
		return (-1);
	if (flags[0] == 1)
		rv1 = putpadding(flags[2] - 1, ' ', &flags[0], flags);
	if (rv1 < 0)
		return (-1);
	return (rv1 + rv2);
}
