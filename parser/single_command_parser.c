/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:02:55 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/06 12:44:56 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

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
	t_list	*tokens;

	i = 0;
	old_i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			i += handle_quotes(&s[i]);
		else if (ft_strncmp(&s[i], "<<", 2) == 0
			|| ft_strncmp(&s[i], ">>", 2) == 0)
			i += handle_double_redirect(&s[i], &tokens);
		else if (s[i] == '<' || s[i] == '>')
			i += handle_simple_redirect(&s[i], &tokens);
		else if (s[i] == ' ')
			i += handle_space(&s[i], i, &old_i, &tokens);
		else
			i++;
	}
	return (tokens);
}

void	get_fds(char **tokens, int fds[2])
{
	int		i;
	char	*s;

	i = 0;
	while (tokens[i])
	{
		if (ft_strchr(tokens[i], '<') || ft_strchr(tokens[i], '>'))
			parse_token(tokens, &i);
		i++;
	}
}

char	**get_args(char **tokens)
{
	int		i;
	int		count;
	char	**args;

	i = 0;
	count = 0;
	while (tokens[i])
	{
		if (is_redirection(tokens, i++))
			i += is_redirection(tokens, i - 1) - 1;
		else
			count++;
	}
	args = calloc(count + 1, sizeof(char *));
	i = 0;
	count = 0;
	while (tokens[i])
	{
		if (is_redirection(tokens, i))
			i += is_redirection(tokens, i);
		else
			args[count++] = tokens[i++];
	}
	return (args);
}

t_cmd	*get_command(char *s)
{
	t_cmd	out;
	char	**tokens;

	tokens = get_tokens(s);
	out.env = msh_getenv();
	get_fds(tokens, out.fd);
	out.argv = get_args(tokens);
	out.next = NULL;
	return (&out);
}
