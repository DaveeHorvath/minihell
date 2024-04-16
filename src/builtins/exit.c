/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:49:40 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/16 19:27:39 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int	msh_exit(char **args, int parent)
{
	if (!args || !args[0])
		exit(0);
	if (args[1])
		ft_dprintf(2, "exit: too many arguments\n");
	if (parent)
		msh_quit(ft_atoi(args[0]));
	exit(ft_atoi(args[0]));
}
