/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:32:31 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 00:49:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr_fd.c
 */

#include "libft.h"

static int	checkflags(int n, int *flags);

/** @brief Writes n to fd
 *
 * @param n Integer to write
 * @param fd File descriptor of the file to write to
 * @retval int Amount of bytes written or -1 if an error occurred
 */
int	ft_putnbr_fd(int n, int fd, int *flags)
{
	char	*nbr;
	int		ret;

	nbr = ft_itoa(n);
	if (!nbr)
		return (-1);
	if (checkflags(n, flags) == 1)
		ret = ft_putstr_fd(nbr, fd);
	else
		ret = ft_putstr_fd(nbr + 1, fd);
	return (ret);
}

static int	checkflags(int n, int *flags)
{
	if (n != INT_MIN)
		return (1);
	if (!flags)
		return (1);
	if (flags[0] == 1 && flags[3] < 11)
		return (1);
	if (flags[2] == 0 && flags[3] == 0)
		return (1);
	if (flags[1] == 1 && flags[2] < (int)ft_intlen(n) && flags[3] < 11)
		return (1);
	if (flags[1] != 1 && flags[3] < 11)
		return (1);
	return (0);
}
