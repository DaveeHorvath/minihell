/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:29:13 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/23 18:32:10 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void	msh_quit(int estatus)
{
	ft_rl_history_save();
	ft_exit(estatus);
}

int	msh_return(int rval)
{
	ft_rl_history_save();
	ft_popall();
	ft_clean();
	return (rval);
}
