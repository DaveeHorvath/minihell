/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:49:40 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/27 15:49:37 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_exit(int estat, int needs_exit)
{
	if (needs_exit)
		ft_exit(estat);
	else
		return (0);
}
