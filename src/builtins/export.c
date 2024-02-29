/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:34:42 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/29 18:34:29 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	export(char *arg);
static int	isvalid(char *arg);

int	msh_export(char **args)
{
	char	rv;

	if (!args)
		return (1);
	if (!*args)
		msh_env(1);
	else
	{
		rv = 0;
		while (*args)
		{
			if (isvalid(*args))
				export(*args);
			else
				rv = 1;
			args++;
		}
	}
	return (rv);
}

static void	export(char *arg)
{
	char	*var;
	char	*val;

	var = arg;
	val = ft_strchr(arg, '=');
	if (val)
		*val++ = '\0';
	msh_setenv(var, val);
}

static int	isvalid(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
		{
			ft_dprintf(2, "export: invalid identifier: %.*s\n",
				ft_strclen(arg, '='), arg);
			return (0);
		}
		i++;
	}
	return (1);
}
