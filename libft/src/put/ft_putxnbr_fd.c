/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:37:45 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 23:16:34 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putxnbr_fd.c
 */

#include "lft_to.h"
#include "lft_put.h"

/** @brief Writes n to fd in hex format
 *
 * @param n Unsigned integer to write
 * @param fd File descriptor to write to
 * @param upper 0 = lowercase output, !0 = uppercase output
 * @retval int Amount of bytes written or -1 if an error occurred
 */
ssize_t	ft_putxnbr_fd(uint64_t n, int32_t fd, uint8_t upper)
{
	const char	*hexarr = "0123456789abcdef";
	int			ret;
	int			out;

	out = 0;
	if (n > 15)
	{
		ret = ft_putxnbr_fd(n / 16, fd, upper);
		out += ret;
		if (upper == 0)
			ret = ft_putchar_fd(hexarr[n % 16], fd);
		else
			ret = ft_putchar_fd(ft_toupper(hexarr[n % 16]), fd);
		if (ret < 0 || out < 1)
			return (-1);
		return (out + ret);
	}
	if (upper == 0)
		return (ft_putchar_fd(hexarr[n % 16], fd));
	return (ft_putchar_fd(ft_toupper(hexarr[n % 16]), fd));
}
