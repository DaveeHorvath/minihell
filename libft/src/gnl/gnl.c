/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:43:58 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 23:10:18 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 */

#include <unistd.h>
#include "lft_str.h"
#include "lft_gnl_internal.h"

/** @brief Reads a line from fd
 *
 * Reads BUFFER_SIZE bytes from fd to a buffer and copies the contents
 * of the buffer to a string until the string has a whole line.
 * @param fd File descriptor to read from
 * @retval char * Pointer to the line
 * or NULL if the allocation failed or EOF was reached
 */
char	*get_next_line(int fd)
{
	static char		buf[499][BUFFER_SIZE + 1];
	int				rv;
	char			*out;

	out = NULL;
	rv = read(fd, NULL, 0);
	while (rv >= 0 && fd < 500)
	{
		if (*buf[fd])
		{
			if (bufcopy(buf[fd], &out) == NULL)
				return (NULL);
		}
		if (out)
		{
			if (out[ft_strlen(out) - 1] == '\n')
				return (out);
		}
		rv = read(fd, buf[fd], BUFFER_SIZE);
		if (rv < 1)
			break ;
	}
	if (fd >= 0 && fd < 500 && rv < 0)
		return (bufshift(buf[fd], buf[fd], 0));
	return (out);
}
