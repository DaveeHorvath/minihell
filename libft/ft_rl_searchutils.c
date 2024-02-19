/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_searchutils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:26:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/19 21:41:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_list	*ft_rl_history_match(t_list *start, char *pattern, char direction)
{
	while (start)
	{
		if (ft_strnstr(start->blk, pattern, ft_strlen(start->blk)))
			break ;
		if (direction == KEY_UP)
			start = start->next;
		else
			start = start->prev;
	}
	return (start);
}

int	ft_rl_history_getpattern(t_rl_input *input, int irow, int icol)
{
	char	c;
	int		row;
	int		col;

	if (read(0, &c, 1) < 0 || (!ft_isprint(c) && c != KEY_DEL && c != KEY_RET))
		return (0);
	if (c == KEY_ALT)
		return (-1);
	if (c == KEY_DEL && input->inputlen == 0)
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
