/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:01:59 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 04:51:22 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putunbr_fd.c
 */

#include "lft_to.h"
#include "lft_put.h"

/** @brief Writes n to fd
 *
 * @param n Unsigned integer to write
 * @param fd File descriptor to write to
 * @retval int Amount of bytes written or -1 if an error occurred
 */
ssize_t	ft_putunbr_fd(uint64_t n, int32_t fd)
{
	char	*nbr;
	int		ret;

	nbr = ft_utoa(n);
	if (!nbr)
		return (-1);
	ret = ft_putstr_fd(nbr, fd);
	return (ret);
}
