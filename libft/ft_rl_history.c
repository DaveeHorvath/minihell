/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:11:12 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:24 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

char	*ft_rl_history_next(void)
{
	t_list	*current;

	current = *ft_rl_history_getcurrent(0);
	if (current->next)
		current = current->next;
	ft_rl_history_setcurrent(current);
	return (current->blk);
}

char	*ft_rl_history_prev(void)
{
	t_list	*current;

	current = *ft_rl_history_getcurrent(0);
	if (current->prev)
		current = current->prev;
	ft_rl_history_setcurrent(current);
	return (current->blk);
}

void	ft_rl_history_update(char *line)
{
	t_list	*current;

	current = *ft_rl_history_getcurrent(0);
	if (!current->prev)
		current->blk = line;
}

void	ft_rl_history_commit(char *line)
{
	t_list	**head;
	t_list	*current;

	head = ft_rl_history_gethead();
	current = *ft_rl_history_getcurrent(0);
	if (line && current->prev)
		(*head)->blk = ft_push(ft_strdup(line));
	else if (!current->blk)
		ft_lstrmnode(head, *head);
	ft_rl_history_getcurrent(1);
}
