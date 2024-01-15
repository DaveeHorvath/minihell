/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:01:59 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 00:50:35 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putunbr_fd.c
 */

#include "libft.h"

/** @brief Writes n to fd
 *
 * @param n Unsigned integer to write
 * @param fd File descriptor to write to
 * @retval int Amount of bytes written or -1 if an error occurred
 */
int	ft_putunbr_fd(unsigned int n, int fd)
{
	char	*nbr;
	int		ret;

	nbr = ft_uitoa(n);
	if (!nbr)
		return (-1);
	ret = ft_putstr_fd(nbr, fd);
	return (ret);
}
