/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:26:57 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 23:15:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putstr_fd.c
 */

#include "lft_put.h"
#include "lft_str.h"

/** @brief Writes s to fd
 *
 * @param *s String to write
 * @param fd File descriptor to write to
 * @retval int Amount of bytes written or -1 if an error occurred
 */
ssize_t	ft_putstr_fd(const char *s, int32_t fd)
{
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	return (write(fd, s, ft_strlen(s)));
}
