/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:34:42 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/27 15:50:40 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	isvalid(char *variable);

int	msh_export(char *variable)
{
	char	*var;
	char	*val;

	if (!variable || !isvalid(variable))
		return (1);
	if (!*variable)
		msh_env();
	var = variable;
	val = ft_strchr(variable, '=');
	if (val)
	{
		*val = '\0';
		val++;
	}
	if (msh_setenv(var, val))
		return (0);
	return (1);
}

static int	isvalid(char *variable)
{
	while (*variable)
	{
		if (!ft_isalnum(*variable) || *variable == '_')
			return (0);
		variable++;
	}
	return (1);
}
