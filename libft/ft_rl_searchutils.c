/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_searchutils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:26:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/13 19:26:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int	ft_rl_history_getpattern(t_rl_input *input, int irow, int icol)
{
	char	c;
	int		row;
	int		col;

	if (read(0, &c, 1) < 0 || (!ft_isprint(c) && c != KEY_DEL))
		return (0);
	if (c != KEY_DEL)
		ft_rl_addchar(input, c);
	else
		ft_rl_rmchar(input);
	ft_rl_term_cur_getpos(&row, &col, 0);
	if (c != KEY_DEL)
		col++;
	else if (col > icol)
		col--;
	ft_rl_term_cur_setpos(irow, icol);
	ft_putstr_fd(TERM_CLEAR_END, 1);
	if (input->input)
		ft_putstr_fd(input->input, 1);
	ft_rl_term_cur_setpos(row, col);
	return (1);
}

int	ft_rl_history_match(t_list **start, char *pattern, char direction)
{
	t_list	*current;

	current = *start;
	while (current)
	{
		if (ft_strnstr(current->blk, pattern, ft_strlen(current->blk)))
			break ;
		if (direction == KEY_DOWN)
			current = current->next;
		else
			current = current->prev;
	}
	if (!current)
		return (0);
	*start = current;
	return (1);
}
