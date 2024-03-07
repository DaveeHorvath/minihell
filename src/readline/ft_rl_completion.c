/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_completion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:35:42 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/07 14:27:10 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_list	*getcompletions(char *pattern, int hascmd);
static t_list	*handlewc(t_rl_wc *wc);
static char		*getpattern(t_rl_input *input);
static int		hascmd(t_rl_input *input);

int	ft_rl_complete(t_rl_input *input)
{
	t_list	*completions;
	char	*pattern;
	int		rv;

	if (!input->i)
		return (1);
	pattern = getpattern(input);
	if (!pattern)
		return (-1);
	completions = getcompletions(ft_push(pattern), hascmd(input));
	ft_popblk(pattern);
	if (!completions)
	{
		ft_rl_wordend(input);
		return (1);
	}
	if (!ft_strchr(pattern, '*'))
		ft_rl_complete_increment(completions, pattern);
	if (!completions->next)
		rv = ft_rl_complete_replace(input, completions->blk);
	else
		rv = ft_rl_complete_multiple(input, completions);
	ft_lstpopall(completions);
	return (rv);
}

static t_list	*getcompletions(char *pattern, int hascmd)
{
	t_list	*completions;

	if (ft_strchr(pattern, '*'))
		completions = handlewc(ft_rl_wildcard_expand(pattern));
	else if (*pattern == '$')
		completions = ft_rl_complete_env(pattern);
	else if (!hascmd)
		completions = ft_rl_complete_cmd(pattern);
	else
		completions = ft_rl_complete_file(pattern);
	return (completions);
}

static t_list	*handlewc(t_rl_wc *wc)
{
	t_list	*completions;
	char	*str;

	if (!wc || !wc->matches)
		return (NULL);
	completions = NULL;
	str = ft_strdup(wc->matches->blk);
	ft_lstpop(wc->matches);
	wc->matches = wc->matches->next;
	while (wc->matches)
	{
		str = ft_strsjoin(str, wc->matches->blk, ' ');
		ft_lstpop(wc->matches);
		wc->matches = wc->matches->next;
	}
	ft_lstadd_front(&completions, ft_lstnew(str));
	return (completions);
}

static char	*getpattern(t_rl_input *input)
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
