/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:38:37 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:24 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_rl_complete_replace(t_rl_input *input, char *word)
{
	size_t	j;
	char	*newline;
	char	*before;
	char	*after;

	j = input->i;
	before = ft_push(ft_substr(input->input, 0, j));
	while (input->input[j] && !ft_isspace(input->input[j]))
		j++;
	after = ft_push(ft_substr(input->input, j, ft_strlen(input->input + j)));
	if (!before || !after)
		return ;
	newline = ft_strjoin(before, word);
	newline = ft_push(ft_strjoin(newline, after));
	ft_popblk(before);
	ft_popblk(after);
	if (!newline)
		return ;
	ft_popblk(input->input);
	input->input = newline;
	while (input->input[input->i] && !ft_isspace(input->input[input->i]))
		input->i++;
}

void	ft_rl_complete_display(t_rl_input *input, t_list *completions)
{
	(void)input;
	(void)completions;
}
