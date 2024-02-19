/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:02:55 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/19 21:36:58 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../libft/libft.h"
#include <fcntl.h>

t_list	*get_tokens(char *s)
{
	int		i;
	int		old_i;
	t_list	*tokens;

	i = 0;
	tokens = NULL;
	while (s[i] == ' ')
		i++;
	old_i = i;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			i += handle_quotes(s, i) + 1;
		else if (ft_strncmp(&s[i], "<<", 2) == 0
			|| ft_strncmp(&s[i], ">>", 2) == 0)
		{
			i += handle_redirect(s, i, &tokens, 2);
			while (s[i] == ' ')
				i++;
			old_i = i;
		}
		else if (s[i] == '<' || s[i] == '>')
		{
			i += handle_redirect(s, i, &tokens, 1);
			while (s[i] == ' ')
				i++;
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

char	*get_filename(char *s, int start)
{
	int	i;

	i = start;
	while (s[i] == ' ')
		i++;
	return (ft_push(ft_strdup(&s[i])));
}

int	open_file(char *s, int fds[2], int type)
{
	int	old_fd;

	(void) old_fd;
	(void) fds;
	if (type == 1)
	{
		old_fd = fds[0];
		fds[0] = open(expand_token(get_filename(s, 1), NULL, none), O_RDONLY);
		if (fds[0] == -1)
		{
			printf("file %s doenst exist\n", expand_token(get_filename(s, 1), NULL, none));
			return (1);
		}
		if (old_fd != -1)
			close(old_fd);
	}
	else if (type == 2)
	{
		old_fd = fds[1];
		fds[1] = open(expand_token(get_filename(s, 2), NULL, none),
				O_CREAT | O_APPEND | O_WRONLY, 0644);
		if (fds[1] == -1)
		{
			printf("file %s doenst exist\n", expand_token(get_filename(s, 2), NULL, none));
			return (1);
		}
		if (old_fd != -1)
			close(old_fd);
	}
	else if (type == 3)
	{
		old_fd = fds[1];
		fds[1] = open(expand_token(get_filename(s, 1), NULL, none),
				O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (fds[1] == -1)
		{
			printf("file %s doenst exist\n", expand_token(get_filename(s, 1), NULL, none));
			return (1);
		}
		if (old_fd != -1)
			close(old_fd);
	}
	return (0);
}

int	get_fds(t_list *tokens, int fds[2])
{
	while (tokens)
	{
		if (tokens->content[0] && (tokens->content[0] == '<'))
		{
			if (ft_strncmp(tokens->content, "<<", 2) == 0)
			{
				if (open_file(tokens->content, fds, 0) == 1)
					return (0);
			}
			else
			{
				if (open_file(tokens->content, fds, 1) == 1)
					return (0);
			}
		}
		else if (tokens->content[0] && tokens->content[0] == '>')
		{
			if (ft_strncmp(tokens->content, ">>", 2) == 0)
			{
				if (open_file(tokens->content, fds, 2) == 1)
					return (0);
			}
			else
			{
				if (open_file(tokens->content, fds, 3) == 1)
					return (0);
			}
		}
		tokens = tokens->next;
	}
	return (1);
}

char	**get_args(t_list *tokens)
{
	int		arg_count;
	char	**args;
	t_list	*start;

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
			args[arg_count++] = expand_token(tokens->content, NULL, none);
		tokens = tokens->next;
	}
	return (args);
}

void	get_def_filedesc(int i, int need_pipe, int *prev_out, t_cmd *current)
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
	}
	else
		current->fd[1] = 1;
}

t_cmd	*get_command(char *s, char **commands, int *prev_out, int i)
{
	t_cmd	*out;
	t_list	*tokens;

	out = ft_push(ft_alloc(sizeof(t_cmd)));
	tokens = get_tokens(s);
	//out->env = msh_getenv();
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
