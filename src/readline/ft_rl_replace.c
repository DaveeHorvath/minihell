/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:38:37 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/26 13:44:57 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int	addinput(t_rl_input *input, char c);

int	ft_rl_complete_replace(t_rl_input *input, char *word)
{
	size_t	j;
	char	*newinput;
	char	*before;
	char	*after;

	ft_rl_wordstart(input);
	j = input->i;
	before = ft_push(ft_substr(input->input, 0, j));
	while (input->input[j] && !ft_isspace(input->input[j]))
		j++;
	after = ft_push(ft_substr(input->input, j, ft_strlen(input->input + j)));
	if (!before || !after)
		return (-1);
	newinput = ft_strjoin(before, word);
	newinput = ft_push(ft_strjoin(newinput, after));
	ft_popblk(before);
	ft_popblk(after);
	if (!newinput)
		return (-1);
	ft_rl_movecursor(input, ft_strlen(word), KEY_RIGHT);
	ft_rl_updateinput(input, newinput, NULL);
	return (1);
}

int	ft_rl_complete_multiple(t_rl_input *input, t_list *completions)
{
	char	c;
	t_list	*first;

	first = completions;
	ft_rl_wordend(input);
	printcompletions(completions, NULL);
	if (read(0, &c, 1) < 0)
		return (-1);
	while (c == KEY_TAB)
	{
		ft_rl_complete_replace(input, completions->blk);
		printcompletions(first, completions->blk);
		completions = completions->next;
		if (!completions)
			completions = first;
		if (read(0, &c, 1) < 0)
			return (-1);
		if (c == KEY_TAB)
			ft_rl_prevword(input);
	}
	return (addinput(input, c));
}

static int	addinput(t_rl_input *input, char c)
{
	int	row;
	int	col;

	if (ft_rl_iscommand(c))
		return (ft_rl_exec(input, c, 1));
	else
	{
		if (c != KEY_DEL)
			ft_rl_addchar(input, c);
		else
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
	}
	return (1);
}
