/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:30:43 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 01:11:17 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putendl_fd.c
 */

#include "libft.h"

/** @brief Writes s followed by a newline to fd
 *
 * @param *s String to write
 * @fd File descriptor of the file to write to
 * @retval int Amount of bytes written or -1 if an error occurred
 */
int	ft_putendl_fd(char *s, int fd)
{
	int	out;
	int	ret;

	if (!s)
	{
		ft_putendl_fd("(null)", fd);
		return (-1);
	}
	ret = ft_putstr_fd(s, fd);
	if (ret < 0)
		return (-1);
	out = ret;
	ret = ft_putchar_fd('\n', fd);
	if (ret < 0)
		return (-1);
	return (out + ret);
}
