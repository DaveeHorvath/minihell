/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:20:16 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 00:26:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putchar_fd.c
 */

#include "libft.h"

/** @brief Writes c to fd
 *
 * @param c Character to write
 * @param fd File descriptor of the file to write to
 * @retval int Amount of bytes written or -1 if an error occurred
 */
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
