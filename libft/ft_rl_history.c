/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:11:12 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/01 22:20:13 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rl_history_next(char r)
{
	static t_list	*history = NULL;

	if (r)
	{
		history = NULL;
		return (NULL);
	}
	if (!history)
		history = *ft_rl_history_gethead();
	if (history->next)
		history = history->next;
	return (history->blk);
}

char	*ft_rl_history_prev(char r)
{
	static t_list	*history = NULL;

	if (r)
	{
		history = NULL;
		return (NULL);
	}
	if (!history)
		history = *ft_rl_history_gethead();
	if (history->prev)
		history = history->prev;
	return (history->blk);
}
