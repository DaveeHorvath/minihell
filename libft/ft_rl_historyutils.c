/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_historyutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:57:38 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/01 22:10:24 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_rl_history_gethead(void)
{
	static t_list	*head = NULL;
	
	return (&head);
}

void	ft_rl_history_add(char *line)
{
	ft_lstadd_front(ft_rl_history_gethead(), ft_lstnew(line));
}

void	ft_rl_history_rm(t_list *node)
{
	ft_lstrmnode(ft_rl_history_gethead(), node);
}
