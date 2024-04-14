/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_history_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:11:33 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/14 16:59:00 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline void	_restore(t_list *cur, t_list *head);

void	ft_rl_hist_restore(void)
{
	t_list	*head;
	t_list	*cur;
	char	*s1;
	char	*s2;

	head = *ft_rl_hist_gethead();
	cur = ft_lstfirst(*ft_rl_hist_getcurrent());
	ft_rl_hist_setcurrent(cur);
	cur = ft_lstlast(cur);
	while (head && cur)
	{
		s1 = ft_push(ft_rl_inputstr(cur->blk, 0));
		s2 = ft_push(ft_rl_inputstr(head->blk, 0));
		if (!ft_strequals(s1, s2))
			_restore(cur, head);
		ft_popblks(2, s1, s2);
		head = head->next;
		cur = cur->prev;
	}
}

static inline void	_restore(t_list *cur, t_list *head)
{
	t_rl_input	*input;

	input = cur->blk;
	if (input)
	{
		ft_rl_popwords(input->head);
		ft_popblk(input);
	}
	cur->blk = ft_rl_dupinput(head->blk);
}
