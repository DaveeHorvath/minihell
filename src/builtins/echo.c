/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:03:20 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/08 14:54:26 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_echo(char **args, int fd)
{
	char	*out;
	char	nl;

	if (!args || !*args)
		return (0);
	nl = 1;
	if (ft_strequals(*args, "-n"))
	{
		nl = 0;
		args++;
	}
	if (*args)
		out = ft_strdup(*args++);
	while (*args)
		out = ft_strsjoin(out, *args++, ' ');
	if (nl)
		ft_putendl_fd(out, fd);
	else
		ft_putstr_fd(out, fd);
	return (0);
}
