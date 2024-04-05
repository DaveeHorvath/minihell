/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:09 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/04 16:49:01 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "env.h"
#include "rl_data.h"
#include "ft_readline.h"

/*
	changes quote if applicable
	returns 1 if change happened otherwise 0
*/
int	update_quote(char c, enum e_quotes *quote)
{
	if (c == '\'' && *quote == none)
	{
		*quote = singlequote;
		return (1);
	}
	else if (c == '\"' && *quote == none)
	{
		*quote = doublequote;
		return (1);
	}
	else if (c == '\'' && *quote == singlequote)
	{
		*quote = none;
		return (1);
	}
	else if (c == '\"' && *quote == doublequote)
	{
		*quote = none;
		return (1);
	}
	return (0);
}

/*
	checks if a filename needs to be expanded
*/
int	needs_filename_expansion(char *s)
{
	int				i;
	enum e_quotes	quote;

	i = 0;
	quote = none;
	while (s[i])
	{
		update_quote(s[i], &quote);
		if (quote == none && s[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

t_tokens	*addfront(t_tokens *new_tokens, t_tokens **tokenlist,
				t_tokens *next)
{
	(*tokenlist)->next = new_tokens;
	while (new_tokens && new_tokens->next)
		new_tokens = new_tokens->next;
	new_tokens->next = next;
	return (new_tokens->next);
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
			if (wildcards->matches->next)
			{
				ft_putstr_fd("minishell ", 2);
				ft_putstr_fd(&s[i], 2);
				ft_putstr_fd(" ambigous redirect\n", 2);
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
	if (s[0] == '<' || s[0] == '>')
	{
		i = 0;
		while (s[i] == ' ')
			i++;
		append(&new, ft_push(ft_strjoin(ft_substr(s, 0, 1),
					ft_rl_wildcard_expand(ft_strdup(&s[i]))->matches->blk)));
	}
	else
	{
		wildcards = ft_rl_wildcard_expand(s);
		matches = wildcards->matches;
		while (matches)
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
	t_tokens	*prev;

	list = *tokens;
	prev = list;
	while (list)
	{
		if (needs_filename_expansion(list->content))
		{
			if (ambigous_redirect(list->content))
				return (0);
			prev = list;
			list = addfront(expand_filenames(list->content), &list, list->next);
		}
		else
		{
			prev = list;
			list = list->next;
		}
	}
	return (1);
}

/*void	expand_alias(t_tokens **tokens, char *s)
{
	t_tokens	*list;
	char		*cont;

	list = *tokens;
	while (list)
	{
		if (list->content[0] != '<' && list->content[0] != '>')
			break ;
		list = list->next;
	}
	if (!list)
		return ;
	cont = list->content;
	if (msh_getalias(list->content) != NULL && !ft_strequals(cont, s))
	{
		list = addfront(get_tokens(msh_getalias
		(list->content)), &list, list->next);
		expand_alias(tokens, cont);
	}
	else
		return ;
}*/

/*
	removes quotes and expands env variables recursivly
*/
char	*expand_token(char *tkn, char *cont, enum e_quotes quote)
{
	int		i;
	int		old_i;

	i = -1;
	old_i = 0;
	while (tkn[++i])
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
			while (tkn[i] && ft_strchr(" \'\"$", tkn[i]) == NULL)
				i++;
			cont = ft_push(ft_strjoin(cont,
						msh_getenv(ft_substr(tkn, old_i, i - old_i))));
			return (expand_token(&tkn[i], cont, quote));
		}
	}
	return (ft_push(ft_strjoin(cont, ft_substr(tkn, old_i, ft_strlen(tkn)))));
}
