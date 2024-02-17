/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:09 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/17 15:56:27 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../libft/libft.h"

char	*msh_getenv(char *s)
{
	printf("# env variable %s serached for\n", s);
	return ("ENV_VAR");
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

char	*expand_token(char *token, char *content, enum e_quotes quote)
{
	int		i;
	int		old_i;

	//printf("token: %s\n", token);
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
	content = ft_push(ft_strjoin(content, ft_substr(token, old_i, ft_strlen(token))));
	return (content);
}
