/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:49:40 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/17 18:11:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int	msh_exit(char **args, int parent)
{
	int	estat;

	if (args && args[0] && args[1])
	{
		ft_dprintf(2, "exit: too many arguments\n");
		return (1);
	}
	estat = 0;
	if (args && args[0])
		estat = ft_atoi(args[0]);
	if (parent)
		msh_quit(estat);
	exit(estat);
}
