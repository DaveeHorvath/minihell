/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:26:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/22 17:29:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_env(void)
{
	size_t	i;
	char	**env;

	env = msh_getenvarr();
	if (!env)
		return (0);
	i = 0;
	while (env[i])
		ft_putendl_fd(env[i++], 1);
	return (1);
}
