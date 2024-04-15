/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:01:15 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/23 11:17:28 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_put.h"
#include "lft_limits.h"

void	ft_debugnbr(int64_t n)
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
