/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:34:42 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/20 15:10:33 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	isvalid(char *variable);

void	msh_export(char *variable)
{
	char	*var;
	char	*val;

	if (!variable || !isvalid(variable))
		exit(1);
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
		exit(0);
	exit (1);
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
