/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:09 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/05 15:51:52 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "env.h"
#include "rl_data.h"
#include "ft_readline.h"

char *msh_getalias(char *s)
{
	(void)s;
	return (NULL);
}

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

int	needs_filename_expansion(char *s)
{
	int				i;
	enum e_quotes	quote;

	i = 0;
	while (s[i])
	{
		update_quote(s[i], &quote);
		if (quote == none && s[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

void	addfront(t_tokens *tokens, t_tokens **tokenlist)
{
	t_tokens	*start;

	start = tokens;
	while (tokens->next)
		tokens = tokens->next;
	tokens->next = *tokenlist;
	*tokenlist = start;
}

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

int	expand_wildcards(t_tokens **tokens)
{
	t_tokens	*list;
	t_tokens	*prev;

	list = *tokens;
	while (list)
	{
		if (needs_filename_expansion((*tokens)->content))
		{
			if (ambigous_redirect(list->content))
				return (0);
			prev->next = list->next;
			addfront(expand_filenames(list->content), &list->next);
		}
		prev = list;
		list = list->next;
	}
	return (1);
}

void	expand_alias(t_tokens **tokens, char *s)
{
	t_tokens	*list;
	t_tokens	*prev;
	char		*cont;

	list = *tokens;
	prev = list;
	while (list)
	{
		if (list->content[0] != '<' && list->content[0] != '>')
			break ;
		prev = list;
		list = list->next;
	}
	if (!list)
		return ;
	cont = list->content;
	if (msh_getalias(list->content) != NULL && !ft_strequals(cont, s))
	{
		prev->next = list->next;
		addfront(get_tokens(msh_getalias(list->content)), &list->next);
		expand_alias(tokens, cont);
	}
	else
		return ;
}

char	*expand_token(char *token, char *content, enum e_quotes quote)
{
	int		i;
	int		old_i;

	i = 0;
	old_i = 0;
	while (token[i])
	{
		if (token[i] == '\'' || token[i] == '\"')
		{
			if (update_quote(token[i], &quote))
			{
				content = ft_push(ft_strjoin(content, ft_substr(token, 0, i)));
				return (expand_token(&token[i + 1], content, quote));
			}
			i++;
		}
		else if (token[i] == '$' && (quote == none || quote == doublequote))
		{
			content = ft_strjoin(content, ft_substr(token, 0, i));
			i++;
			old_i = i;
			while (token[i] && ft_strchr(" \'\"$", token[i]) == NULL)
				i++;
			content = ft_push(ft_strjoin(content, msh_getenv(ft_substr(token, old_i, i - old_i))));
			return (expand_token(&token[i], content, quote));
		}
		else
			i++;
	}
	return (ft_push(ft_strjoin(content, ft_substr(token, old_i, ft_strlen(token)))));
}
