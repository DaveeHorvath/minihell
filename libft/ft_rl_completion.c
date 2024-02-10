/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_completion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:35:42 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 02:10:10 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_list	*getcompletions(char *word, int isfirst);
static int		hascmd(char *line, size_t i);

void	ft_rl_complete(size_t *i, size_t plen, char **line)
{
	t_list	*completions;
	char	*word;

	if (*i > 0 && !ft_isspace((*line)[*i - 1]))
		ft_rl_prevword(i, *line, plen);
	word = ft_push(ft_substr(*line, *i, ft_strclen(*line + *i, ' ')));
	if (!word)
		return ;
	completions = getcompletions(word, hascmd(*line, *i));
	if (!completions)
		return ;
	if (!completions->next)
		ft_rl_complete_replace(i, line, completions->blk);
	else
		ft_rl_complete_display(i, line, completions);
	ft_lstpopall(completions);
	ft_popblk(word);
}

static t_list	*getcompletions(char *word, int isfirst)
{
	t_list	*completions;

	if (*word == '$')
		completions = ft_rl_complete_env(word);
	else if (isfirst)
		completions = ft_rl_complete_cmd(word);
	else
		completions = ft_rl_complete_file(word);
	return (completions);
}

static int	hascmd(char *line, size_t i)
{
	while (i > 0)
	{
		if (!ft_isspace(line[i - 1]))
		{
			if (line[i - 1] == '|' || line[i - 1] == '&')
				return (1);
			return (0);
		}
		i--;
	}
	return (1);
}
