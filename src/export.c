/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:34:42 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/22 17:56:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_export(char *variable)
{
	size_t	i;
	char	*var;
	char	*val;

	if (!variable)
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
	if (ft_setenv(var, val))
		exit(0);
	exit (1);
}
