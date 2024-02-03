/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_historyutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:57:38 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/03 20:22:54 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_rl_history_gethead(void)
{
	static t_list	*head = NULL;
	
	return (&head);
}

t_list	**ft_rl_history_getcurrent(char r)
{
	static t_list	*current = NULL;

	if (r)
	{
		current = NULL;
		return (NULL);
	}
	if (!current)
		current = *ft_rl_history_gethead();
	return (&current);
}

void	ft_rl_history_setcurrent(t_list *node)
{
	*ft_rl_history_getcurrent(0) = node;
}

void	ft_rl_history_recycle(void)
{
	t_list	**head;
	t_list	*last;

	head = ft_rl_history_gethead();
	last = ft_lstlast(*ft_rl_history_getcurrent(0));
	if (!head || !last)
		return ;
	ft_popblk(last->blk);
	last->blk = NULL;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
}
