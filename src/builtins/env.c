/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:26:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/15 17:40:07 by dhorvath         ###   ########.fr       */
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
	{
		if (ft_strncmp(env[i], "?=", 2) != 0)
			ft_putendl_fd(env[i], fd);
		i++;
	}
	return (0);
}
