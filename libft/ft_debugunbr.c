/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:18:19 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:16 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_debugunbr(unsigned long n)
{
	if (n > 9)
	{
		ft_debugunbr(n / 10);
		ft_putchar_fd(n % 10 + '0', DEBUGFD);
		return ;
	}
	ft_putchar_fd(n + '0', DEBUGFD);
}
