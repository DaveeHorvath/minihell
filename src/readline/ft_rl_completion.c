/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_completion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:35:42 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/02 12:17:39 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_list	*getcompletions(char *word, int hascmd);
static char		*getword(t_rl_input *input);
static int		hascmd(t_rl_input *input);

int	ft_rl_complete(t_rl_input *input)
{
	size_t	i;
	t_list	*completions;
	char	*word;
	int		rv;

	if (!input->i)
		return (1);
	i = input->i;
	word = getword(input);
	if (!word)
		return (-1);
	completions = getcompletions(ft_push(word), hascmd(input));
	ft_popblk(word);
	if (!completions)
		return (1);
	ft_rl_complete_increment(completions, word);
	if (!completions->next)
		rv = ft_rl_complete_replace(input, completions->blk);
	else
		rv = ft_rl_complete_multiple(input, completions);
	ft_lstpopall(completions);
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

static char	*getword(t_rl_input *input)
{
	char	*out;

	if (!input->input[input->inputlen]
		&& ft_isspace(input->input[input->inputlen]))
		return (ft_push(ft_strdup("")));
	ft_rl_wordstart(input);
	out = ft_push(ft_substr(input->input, input->i,
				input->inputlen - input->i));
	return (out);
}

// shit, improve
static int	hascmd(t_rl_input *input)
{
	size_t	i;

	i = input->i;
	while (i > 0)
	{
		if (!ft_isspace(input->input[i - 1]))
		{
			if (input->input[i - 1] == '|' || input->input[i - 1] == '&')
				return (0);
			return (1);
		}
		(i)--;
	}
	return (0);
}
