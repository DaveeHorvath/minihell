/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:38:37 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 02:10:10 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_rl_complete_replace(size_t *i, char **line, char *word)
{
	size_t	j;
	char	*newline;
	char	*before;
	char	*after;

	j = *i;
	before = ft_push(ft_substr(*line, 0, j));
	while ((*line)[j] && !ft_isspace((*line)[j]))
		j++;
	after = ft_push(ft_substr(*line, j, ft_strlen(*line + j)));
	if (!before || !after)
		return ;
	newline = ft_strjoin(before, word);
	newline = ft_push(ft_strjoin(newline, after));
	ft_popblk(before);
	ft_popblk(after);
	if (!newline)
		return ;
	ft_popblk(*line);
	*line = newline;
	while ((*line)[*i] && !ft_isspace((*line)[*i]))
		(*i)++;
}

void	ft_rl_complete_display(size_t *i, char **line, t_list *completions)
{
	(void)i;
	(void)line;
	(void)completions;
}
