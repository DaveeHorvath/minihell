/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:33:01 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/23 14:44:17 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	msh_pwd(void)
{
	char	*path;

	path = msh_getenv("PWD");
	if (!path)
		exit(1);
	ft_putendl_fd(path, 1);
	exit(0);
}
