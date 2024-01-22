/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:03:20 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/22 15:39:43 by ivalimak         ###   ########.fr       */
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
