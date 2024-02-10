/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_inpututils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:29:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:24 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_rl_nextword(t_rl_input *input)
{
	size_t	j;
	int		row;
	int		col;

	j = 0;
	ft_rl_term_cur_getpos(&row, &col, 0);
	while (input->input[input->i + j] \
		&& !ft_isspace(input->input[input->i + j]))
		j++;
	while (ft_isspace(input->input[input->i + j]))
		j++;
	col += j;
	input->i += j;
	ft_rl_term_cur_setpos(row, col);
}

void	ft_rl_prevword(t_rl_input *input)
{
	size_t	j;
	int		row;
	int		col;

	j = 0;
	ft_rl_term_cur_getpos(&row, &col, 0);
	if (!input->input[input->i] && input->i > 0)
		j++;
	if (input->i - j > 0 && ft_isspace(input->input[input->i - j - 1]))
		j++;
	while (ft_isspace(input->input[input->i - j]))
		j++;
	while (input->i - j > 0 && !ft_isspace(input->input[input->i - j - 1]))
		j++;
	col -= j;
	input->i -= j;
	ft_rl_term_cur_setpos(row, col);
}
