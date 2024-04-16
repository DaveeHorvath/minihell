/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:29:13 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/28 22:41:04 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void	msh_quit(int estatus)
{
	ft_rl_hist_save(RL_HFNAME);
	ft_exit(estatus);
}

int	msh_return(int rval)
{
	ft_rl_hist_save(RL_HFNAME);
	ft_popall();
	ft_clean();
	return (rval);
}
