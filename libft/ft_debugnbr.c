/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:01:15 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:16 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_debugnbr(long n)
{
	if (n == LONG_MIN)
	{
		ft_putstr_fd("-9223372036854775807", DEBUGFD);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', DEBUGFD);
	}
	if (n > 9)
	{
		ft_debugnbr(n / 10);
		ft_putchar_fd(n % 10 + '0', DEBUGFD);
		return ;
	}
	ft_putchar_fd(n + '0', DEBUGFD);
}
