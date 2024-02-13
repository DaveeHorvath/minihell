/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:27:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/13 19:49:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_rl_history_search(char direction)
{
	int		row;
	int		col;
	t_list	*initial;
	t_list	*current;

	current = *ft_rl_history_getcurrent(0);
	if ((direction == KEY_DOWN && !current->prev)
		|| (direction == KEY_UP && !current->next))
		return ;
	initial = current;
	ft_rl_term_cur_getpos(&row, &col, 0);
}
