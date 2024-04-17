/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:28:21 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/17 14:20:28 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_dprintf.c
 */

#include "libft.h"

/** @brief Prints the format string to fd
 *
 * Functions exactly like ft_printf apart from printing to fd instead of stdout
 * @param fd File descriptor to print to
 * @param *s Format string to print
 * @param ... Arguments for format string conversions
 * @retval int Amount of characters printed or -1 if an error occurred
 */
int64_t	ft_dprintf(int32_t fd, const char *f, ...)
{
	va_list	args;
	int		ret;
	int		out;

	if (!f)
		return (-1);
	ret = 1;
	out = 0;
	ft_pfsetfd(fd);
	va_start(args, f);
	while (*f && ret >= 0)
	{
		if (*f != '%')
			ret = ft_putchar_fd(*f, ft_pfgetfd());
		else
			ret = ft_printformat(&f, args);
		out += ret;
		f++;
	}
	va_end(args);
	if (ret < 0)
		return (-1);
	return (out);
}
