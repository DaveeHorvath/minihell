/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:02:55 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/01 16:11:01 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*expand_token(char *s, size_t start, size_t end)
{
	return (ft_substr(s, start, end));
}

char	**get_tokens(char *s)
{
	int		token_count;
	int		current_token;
	size_t	i;
	size_t	old_i;
	char	**tokens;

	i = 0;
	current_token = 0;
	token_count = count_tokens(s);
	tokens = calloc(token_count, sizeof(char *));
	while (s[i])
	{
		while (isspace(s[i]))
			i++;
		old_i = i;
		while (!isspace(s[i]) && s[i])
		{
			if (s[i] == '\'' || s[i] == '\"')
				i += skip_til(s[i]);
			i++;
		}
		if (i != old_i)
			tokens[current_token++] = expand_token(s, old_i, i);
	}
	return (tokens);
}

t_cmd	*get_command(char *s)
{
	t_cmd	out;
	char	**tokens;

	tokens = get_tokens(s);
	out.env = get_env();
	get_fds(tokens, out.fd);
	out.argv = get_args(tokens);
	out.next = NULL;
	return (&out);
}
