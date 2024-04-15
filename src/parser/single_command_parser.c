/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:02:55 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/15 17:18:20 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "env.h"

static void		get_def_filedesc(int i, int need_pipe,
					int *prev_out, t_cmd *current);

/*
	constructs t_cmd by parsing the current command
	into arguments and redirections
	//expand_wildcards(&tokens);
*/
t_cmd	*get_command(char *s, char **commands, int *prev_out, int i)
{
	t_cmd		*out;
	t_tokens	*tokens;

	out = ft_push(ft_alloc(sizeof(t_cmd)));
	out->original = s;
	tokens = get_tokens(ft_strtrim(ft_push(s), " "));
	out->env = msh_getenvarr();
	if (commands[i + 1])
		get_def_filedesc(i, 1, prev_out, out);
	else
		get_def_filedesc(i, 0, prev_out, out);
	if (get_fds(tokens, out->fd) == 0)
		out->exitcode = -1;
	else
		out->exitcode = 0;
	out->argv = get_args(tokens);
	out->next = NULL;
	return (out);
}

/*
	tokenises the string with respect to quotes
*/
t_tokens	*get_tokens(char *s)
{
	int			i;
	int			old_i;
	t_tokens	*tokens;

	ft_push(s);
	i = 0;
	tokens = NULL;
	old_i = i;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			i += handle_quotes(s, i) + 1;
		else if (s[i] == '<' || s[i] == '>')
		{
			i += handle_redirect(s, i, &tokens, 1 + (s[i + 1] == s[i]));
			old_i = i;
		}
		else if (s[i] == ' ')
			i += handle_space(s, i, &old_i, &tokens);
		else
			i++;
	}
	if (old_i != i)
		handle_space(s, i, &old_i, &tokens);
	return (tokens);
}

/*
	from the tokens takes most recent fds
*/
int	get_fds(t_tokens *tokens, int fds[2])
{
	while (tokens)
	{
		if (tokens->content[0] && (tokens->content[0] == '<'))
		{
			if (handle_infile(tokens, fds) == 0)
				return (0);
		}
		else if (tokens->content[0] && tokens->content[0] == '>')
		{
			if (!handle_outfile(tokens, fds))
				return (0);
		}
		tokens = tokens->next;
	}
	return (1);
}

/*
	filters and expands the tokens
*/
char	**get_args(t_tokens *tokens)
{
	int			arg_count;
	char		**args;
	t_tokens	*start;

	start = tokens;
	arg_count = 0;
	while (tokens)
	{
		if (tokens->content[0] != '<' && tokens->content[0] != '>')
			arg_count++;
		tokens = tokens->next;
	}
	args = ft_push(ft_calloc(arg_count + 1, sizeof(char *)));
	arg_count = 0;
	tokens = start;
	while (tokens)
	{
		if (tokens->content[0] != '<' && tokens->content[0] != '>')
		{
			args[arg_count++] = expand_token(tokens->content, NULL, none);
		}
		tokens = tokens->next;
	}
	return (args);
}

/*
	opens and assigns pipes as needed
*/
static void	get_def_filedesc(int i, int need_pipe,
	int *prev_out, t_cmd *current)
{
	int	pipefds[2];

	if (i != 0)
		current->fd[0] = *prev_out;
	else
		current->fd[0] = 0;
	if (need_pipe)
	{
		pipe(pipefds);
		current->fd[1] = pipefds[1];
		*prev_out = pipefds[0];
		current->pipe_end = *prev_out;
	}
	else
	{
		current->fd[1] = 1;
		current->pipe_end = -1;
	}
}
