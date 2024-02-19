/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_inpututils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:29:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/12 14:46:16 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_rl_nextword(t_rl_input *input)
{
	size_t	i;
	int		row;
	int		col;

	i = 0;
	ft_rl_wordend(input);
	ft_rl_term_cur_getpos(&row, &col, 0);
	while (ft_isspace(input->input[input->i + i]))
		i++;
	input->i += i;
	col += i;
	ft_rl_term_cur_setpos(row, col);
}

void	ft_rl_prevword(t_rl_input *input)
{
	size_t	i;
	int		row;
	int		col;

	i = 0;
	ft_rl_term_cur_getpos(&row, &col, 0);
	if (!input->input[input->i] && input->i > 0)
		i++;
	if (input->i - i > 0 && ft_isspace(input->input[input->i - i - 1]))
		i++;
	while (ft_isspace(input->input[input->i - i]))
		i++;
	input->i -= i;
	col -= i;
	ft_rl_term_cur_setpos(row, col);
	ft_rl_wordstart(input);
}

void	ft_rl_wordstart(t_rl_input *input)
{
	size_t	i;
	int		row;
	int		col;

	i = 0;
	ft_rl_term_cur_getpos(&row, &col, 0);
	while (input->i - i)
	{
		if (ft_isspace(input->input[input->i - i - 1]))
			break ;
		i++;
	}
	input->i -= i;
	col -= i;
	ft_rl_term_cur_setpos(row, col);
}

void	ft_rl_wordend(t_rl_input *input)
{
	size_t	i;
	int		row;
	int		col;

	i = 0;
	ft_rl_term_cur_getpos(&row, &col, 0);
	while (input->input[input->i + i])
	{
		if (ft_isspace(input->input[input->i + i + 1]))
			break ;
		i++;
	}
	input->i += i;
	col += i;
	ft_rl_term_cur_setpos(row, col);
}
