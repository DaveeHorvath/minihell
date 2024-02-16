/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:33:20 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/16 20:10:47 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_rl_redisplay(t_rl_input *input)
{
	int	row;
	int	col;

	ft_rl_term_cur_getpos(&row, &col, 0);
	ft_rl_term_cur_inputstart();
	ft_putstr_fd(TERM_CLEAR_END, 1);
	if (input->input)
		ft_putstr_fd(input->input, 1);
	ft_rl_term_cur_setpos(row, col);
}

void	ft_rl_updateinput(t_rl_input *input, char *newinput)
{
	int	row;
	int	col;

	ft_popblk(input->input);
	input->input = ft_push(newinput);
	input->inputlen = ft_strlen(input->input);
	input->i = input->inputlen;
	ft_rl_term_cur_inputstart();
	ft_rl_term_cur_getpos(&row, &col, 0);
	ft_putstr_fd(TERM_CLEAR_END, 1);
	if (input->input)
		ft_putstr_fd(input->input, 1);
	ft_rl_term_cur_setpos(row, col + input->inputlen);
}

void	ft_rl_addchar(t_rl_input *input, char c)
{
	char	*newinput;

	ft_dprintf(2, "addchar: char: '%c' (%d)\n", c, c);
	if (!input->input)
	{
		input->input = ft_push(ft_calloc(2, sizeof(char)));
		if (input->input)
			*input->input = c;
		input->i++;
		input->inputlen = ft_strlen(input->input);
		return ;
	}
	newinput = ft_calloc(ft_getblksize(input->input) + 1, sizeof(char));
	ft_popblk(input->input);
	if (newinput)
	{
		ft_strlcpy(newinput, input->input, input->i + 1);
		newinput[input->i] = c;
		ft_strlcpy(&newinput[input->i + 1],
			&input->input[input->i], input->inputlen - input->i);
	}
	input->i++;
	input->input = ft_push(newinput);
	input->inputlen = ft_strlen(newinput);
}

void	ft_rl_rmchar(t_rl_input *input)
{
	char	*newinput;

	if (input->i)
		ft_dprintf(2, "rmchar: char: '%c' (%d)\n", input->input[input->i - 1], input->input[input->i - 1]);
	if (!input->input)
		return ;
	newinput = NULL;
	if (ft_getblksize(input->input) > 1)
		newinput = ft_calloc(ft_getblksize(input->input) - 1, sizeof(char));
	ft_popblk(input->input);
	if (newinput)
	{
		ft_strlcpy(newinput, input->input, input->i);
		ft_strlcpy(&newinput[input->i - 1],
			&input->input[input->i], input->inputlen - input->i);
	}
	input->i--;
	input->input = ft_push(newinput);
	input->inputlen = ft_strlen(newinput);
}

int	ft_rl_getinput(t_rl_input *input)
{
	int		row;
	int		col;
	char	c;

	if (read(0, &c, 1) < 0)
		return (-1);
	if (ft_rl_iscommand(c))
		return (ft_rl_exec(input, c, 0));
	if (c != KEY_DEL)
		ft_rl_addchar(input, c);
	else if (input->i)
		ft_rl_rmchar(input);
	ft_rl_term_cur_getpos(&row, &col, 1);
	if (c != KEY_DEL)
		col++;
	else if (col > (int)input->promptlen + 1)
		col--;
	ft_rl_history_update(input->input);
	ft_rl_term_cur_inputstart();
	ft_putstr_fd(TERM_CLEAR_END, 1);
	if (input->input)
		ft_putstr_fd(input->input, 1);
	ft_rl_term_cur_setpos(row, col);
	return (1);
}