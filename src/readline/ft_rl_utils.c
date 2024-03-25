/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:32:10 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/25 10:31:00 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int	ft_rl_isdir(const char *path)
{
	static struct stat	file;

	stat(path, &file);
	if (file.st_mode & S_IFDIR)
		return (1);
	return (0);
}
