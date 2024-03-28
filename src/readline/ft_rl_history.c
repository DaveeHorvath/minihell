/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:08:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/28 17:46:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

t_rl_input	*ft_rl_hist_getnext(void)
{
	t_list	*current;

	current = *ft_rl_hist_getcurrent();
	if (!current)
		return (NULL);
	if (current->next)
		current = current->next;
	ft_rl_hist_setcurrent(current);
	return (current->blk);
}

t_rl_input	*ft_rl_hist_getprev(void)
{
	t_list	*current;

	current = *ft_rl_hist_getcurrent();
	if (!current)
		return (NULL);
	if (current->prev)
		current = current->prev;
	ft_rl_hist_setcurrent(current);
	return (current->blk);
}

void	ft_rl_hist_commit(t_rl_input *input)
{
	const t_list	*current = *ft_rl_hist_getcurrent();

	if (!input || (current && current->prev))
		return ;
	ft_lstadd_back(ft_rl_hist_gethead(), ft_lstnew(ft_rl_dupinput(input)));
}
