/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_matchutils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:55:10 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/27 14:13:56 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_rl_complete_checkdirs(char *path, t_list *completions)
{
	t_list		*tmp;

	tmp = completions;
	while (tmp)
	{
		if (path)
		{
			ft_popblk(tmp->blk);
			tmp->blk = ft_push(ft_strsjoin(path, tmp->blk, '/'));
		}
		if (ft_rl_isdir(tmp->blk))
		{
			ft_popblk(tmp->blk);
			tmp->blk = ft_push(ft_strjoin(tmp->blk, "/"));
		}
		tmp = tmp->next;
	}
}
