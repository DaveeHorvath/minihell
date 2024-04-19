/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:33:01 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/19 17:15:25 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_pwd(int fd)
{
	char	cwd[MAXPATHLEN];

	ft_putendl_fd(getcwd((char *)cwd, MAXPATHLEN), fd);
	return (0);
}
