/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:33:01 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/29 18:46:52 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_pwd(int fd)
{
	char	*path;

	path = msh_getenv("PWD");
	if (!path)
		return (1);
	ft_putendl_fd(path, fd);
	return (0);
}
