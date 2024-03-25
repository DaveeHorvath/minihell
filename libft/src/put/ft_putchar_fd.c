/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:20:16 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 13:33:24 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putchar_fd.c
 */

#include "lft_put.h"

/** @brief Writes c to fd
 *
 * @param c Character to write
 * @param fd File descriptor of the file to write to
 * @retval int Amount of bytes written or -1 if an error occurred
 */
ssize_t	ft_putchar_fd(uint8_t c, int32_t fd)
{
	return (write(fd, &c, 1));
}
