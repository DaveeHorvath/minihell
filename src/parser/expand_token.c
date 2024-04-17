/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:09 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/17 15:44:25 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_printf.h"
#include "parser.h"
#include "libft.h"
#include "env.h"
#include "ft_readline.h"

/*
	checks if a filename needs to be expanded
*/
int	needs_filename_expansion(char *s)
{
	int				i;
	enum e_quotes	quote;

	i = 0;
	quote = none;
	while (s && s[i])
	{
		update_quote(s[i], &quote);
		if (quote == none && s[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

/*
	checks for redirection and multiple redirects
*/
int	ambigous_redirect(char *s)
{
	int		i;
	t_rl_wc	*wildcards;

	if (s[0] == '<' || s[0] == '>')
	{
		i = 1;
		while (s[i] && s[i] == ' ')
			i++;
		if (ft_strchr(&s[i], '*'))
		{
			wildcards = ft_rl_wildcard_expand(ft_strdup(&s[i]));
			if (wildcards && wildcards->matches && wildcards->matches->next)
			{
				ft_dprintf(2, "minishell: %s: ambigous redirect\n", &s[i]);
				return (1);
			}
		}
		return (0);
	}
	return (0);
}

/*
	uses wildcard expansion if applicable
	needs to remove original arg and if no matches are found put it back
*/
t_tokens	*expand_filenames(char *s)
{
	t_tokens	*new;
	t_rl_wc		*wildcards;
	t_list		*matches;
	int			i;

	new = NULL;
	if (s && (s[0] == '<' || s[0] == '>'))
	{
		i = 1;
		while (s[i] == ' ')
			i++;
		append(&new, ft_push(ft_strjoin(ft_substr(s, 0, 1),
					ft_rl_wildcard_expand(ft_strdup(&s[i]))->matches->blk)));
	}
	else if (s)
	{
		wildcards = ft_rl_wildcard_expand(s);
		if (wildcards)
			matches = wildcards->matches;
		while (wildcards && matches)
		{
			append(&new, matches->blk);
			matches = matches->next;
		}
	}
	return (new);
}

/*
	wildcard expansion for all the tokens
*/
int	expand_wildcards(t_tokens **tokens)
{
	t_tokens	*list;
	t_tokens	*expanded;

	list = *tokens;
	while (list)
	{
		if (needs_filename_expansion(list->content))
		{
			if (ambigous_redirect(list->content))
				return (0);
			expanded = expand_filenames(list->content);
			if (expanded)
			{
				list->content = "";
				list = addfront(expanded, &list, list->next);
			}
		}
		list = list->next;
	}
	return (1);
}

/*
	removes quotes and expands env variables recursivly
*/
char	*expand_token(char *tkn, char *cont, enum e_quotes quote)
{
	int		i;
	int		old_i;

	i = -1;
	old_i = 0;
	while (tkn && tkn[++i])
	{
		if (tkn[i] == '\'' || tkn[i] == '\"')
		{
			if (update_quote(tkn[i], &quote))
				return (expand_token(&tkn[i + 1], ft_push(ft_strjoin(cont,
								ft_substr(tkn, 0, i))), quote));
		}
		else if (tkn[i] == '$' && (quote == none || quote == doublequote))
		{
			cont = ft_push(ft_strjoin(cont, ft_substr(tkn, 0, i++)));
			old_i = i;
			while (tkn[i] && (ft_isalpha(tkn[i]) || ft_isdigit(tkn[i])))
				i++;
			cont = ft_push(ft_strjoin(cont,
						msh_getenv(ft_substr(tkn, old_i, i - old_i))));
			return (expand_token(&tkn[i], cont, quote));
		}
	}
	return (ft_push(ft_strjoin(cont, ft_substr(tkn, old_i, ft_strlen(tkn)))));
}
