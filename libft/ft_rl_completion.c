/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_completion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:35:42 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/11 00:35:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_list	*getcompletions(char *word, int hascmd);
static char		*getword(t_rl_input *input, size_t *i);
static int		hascmd(t_rl_input *input, size_t *i);

int	ft_rl_complete(t_rl_input *input)
{
	size_t	i;
	t_list	*completions;
	char	*word;
	int		rv;

	i = input->i;
	word = getword(input, &i);
	if (!word)
		return (-1);
	completions = getcompletions(word, hascmd(input, &i));
	if (!completions)
		return (1);
	if (!completions->next)
		rv = ft_rl_complete_replace(input, completions->blk);
	else
		rv = ft_rl_complete_multiple(input, completions);
	ft_lstpopall(completions);
	ft_popblk(word);
	return (rv);
}

static t_list	*getcompletions(char *word, int hascmd)
{
	t_list	*completions;

	if (*word == '$')
		completions = ft_rl_complete_env(word);
	else if (!hascmd)
		completions = ft_rl_complete_cmd(word);
	else
		completions = ft_rl_complete_file(word);
	return (completions);
}

static char	*getword(t_rl_input *input, size_t *i)
{
	char	*out;

	while (*i > 0 && !ft_isspace(input->input[*i]))
		(*i)--;
	if (ft_isspace(input->input[*i]))
		(*i)++;
	out = ft_push(ft_substr(input->input, *i,
				ft_strclen(input->input + *i, ' ')));
	return (out);
}

// shit, improve
static int	hascmd(t_rl_input *input, size_t *i)
{
	while (*i > 0)
	{
		if (!ft_isspace(input->input[*i - 1]))
		{
			if (input->input[*i - 1] == '|' || input->input[*i - 1] == '&')
				return (0);
			return (1);
		}
		(*i)--;
	}
	return (0);
}
