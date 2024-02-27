/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:03:20 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/27 15:48:09 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_echo(char *s, char nl)
{
	if (nl)
		ft_putendl_fd(s, 1);
	else
		ft_putstr_fd(s, 1);
	return (0);
}
