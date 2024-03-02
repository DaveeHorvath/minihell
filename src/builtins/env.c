/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:26:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/29 18:05:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_env(int fd)
{
	size_t	i;
	char	**env;

	env = msh_getenvarr();
	if (!env)
		return (1);
	i = 0;
	while (env[i])
		ft_putendl_fd(env[i++], fd);
	return (0);
}
