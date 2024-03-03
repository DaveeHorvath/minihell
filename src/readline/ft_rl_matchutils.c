/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_matchutils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:55:10 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/03 15:23:43 by ivalimak         ###   ########.fr       */
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

void	ft_rl_wildcard_rmdot(t_rl_wc *wc)
{
	t_list	*matches;

	matches = wc->matches;
	while (matches)
	{
		ft_memmove(matches->blk, matches->blk + 2, ft_strlen(matches->blk) - 1);
		matches = matches->next;
	}
}

void	ft_rl_wildcard_pop(t_rl_wc *wc)
{
	if (!wc)
		return ;
	ft_popblk(wc);
	ft_popblk(wc->pattern);
	while (wc->matches)
	{
		if (!wc->matches->prev)
			break ;
		wc->matches = wc->matches->prev;
	}
	ft_lstpopall(wc->matches);
}

int	ft_rl_wildcard_checkalloc(t_rl_wc *wc1, t_rl_wc *wc2, char **arr)
{
	if (!wc1 || !arr)
	{
		ft_rl_wildcard_pop(wc1);
		ft_rl_wildcard_pop(wc2);
		if (arr)
		{
			ft_popblk(arr);
			while (*arr)
				ft_popblk(*arr++);
		}
		return (1);
	}
	return (0);
}
