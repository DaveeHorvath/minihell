/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_completion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:35:42 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:23 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_list	*getcompletions(char *word, int hascmd);
static int		hascmd(t_rl_input *input);

void	ft_rl_complete(t_rl_input *input)
{
	t_list	*completions;
	char	*word;

	if (input->i > 0 && !ft_isspace(input->input[input->i - 1]))
		ft_rl_prevword(input);
	word = ft_push(ft_substr(input->input, input->i,
			ft_strclen(input->input + input->i, ' ')));
	if (!word)
		return ;
	completions = getcompletions(word, hascmd(input));
	if (!completions)
		return ;
	if (!completions->next)
		ft_rl_complete_replace(input, completions->blk);
	else
		ft_rl_complete_display(input, completions);
	ft_lstpopall(completions);
	ft_popblk(word);
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
				return (1);
			return (0);
		}
		i--;
	}
	return (1);
}
