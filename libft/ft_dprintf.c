/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:28:21 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 11:35:08 by ivalimak         ###   ########.fr       */
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
int	ft_dprintf(int fd, const char *s, ...)
{
	va_list	args;
	int		ret;
	int		out;

	if (!s)
		return (-1);
	ret = 1;
	out = 0;
	ft_pfsetfd(fd);
	va_start(args, s);
	while (*s && ret >= 0)
	{
		if (*s != '%')
			ret = ft_putchar_fd(*s, ft_pfgetfd());
		else
			ret = ft_printformat(&s, args);
		out += ret;
		s++;
	}
	va_end(args);
	if (ret < 0)
		return (-1);
	return (out);
}
