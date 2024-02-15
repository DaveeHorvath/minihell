/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:09 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/15 14:56:29 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

void	update_quote(char c, enum e_quotes *quote)
{
	if (c == '\'' && *quote == none)
		*quote = singlequote;
	else if (c == '\"' && *quote == none)
		*quote = doublequote;
	else if (c == '\'' && *quote == singlequote)
		*quote = none;
	else if (c == '\"' && *quote == doublequote)
		*quote = none;
}

char	*expand_token(char *token, char *content, enum e_quotes quote)
{
	int		i;
	int		old_i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '\'' || token[i] == '\"')
		{
			update_quote(token[i], &quote);
			content = ft_strjoin(content, ft_substr(token, 0, i));
			content = ft_strjoin(content,
					expand_token(&token[i + 1], content, quote));
			return (content);
		}
		else if (token[i] == '$' && quote == none || quote == doublequote)
		{
			old_i = i;
			while (token[i] && ft_strchr(" \'\"$", token[i]) == NULL)
				i++;
			content = ft_strjoin(content, msh_getenv(ft_substr(token, old_i, i - old_i)));
		}
		else
			i++;
	}
	return (content);
}
