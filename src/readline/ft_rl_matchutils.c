/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_matchutils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:55:10 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/07 14:31:01 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static char	*escapespaces(char *path);

void	ft_rl_complete_checkdirs(char *path, t_list *completions)
{
	t_list		*tmp;

	tmp = completions;
	while (tmp)
	{
		if (path)
		{
			ft_popblk(tmp->blk);
			if (ft_strequals(path, "/"))
				tmp->blk = ft_push(ft_strjoin(path, tmp->blk));
			else
				tmp->blk = ft_push(ft_strsjoin(path, tmp->blk, '/'));
		}
		if (ft_rl_isdir(tmp->blk))
		{
			ft_popblk(tmp->blk);
			tmp->blk = ft_push(ft_strjoin(tmp->blk, "/"));
		}
		tmp->blk = ft_push(escapespaces(tmp->blk));
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

static char	*escapespaces(char *path)
{
	char	**arr;
	size_t	i;

	arr = ft_pusharr(ft_split(path, ' '));
	ft_popblk(path);
	if (!arr)
		return (path);
	if (ft_strequals(arr[0], path))
	{
		ft_popblks(2, arr, *arr);
		return (path);
	}
	i = 0;
	path = NULL;
	while (arr[i])
	{
		path = ft_strjoin(path, arr[i]);
		ft_popblk(arr[i++]);
		if (arr[i])
			path = ft_strjoin(path, "\\ ");
	}
	ft_popblk(arr);
	return (path);
}
