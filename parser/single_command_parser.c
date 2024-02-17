/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:02:55 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/17 19:16:05 by dhorvath         ###   ########.fr       */
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

void	open_file(char *s, int fds[2], int type)
{
	int	old_fd;

	(void) old_fd;
	(void) fds;
	if (type == 1)
	{
		printf("opening -%s- as read\n", expand_token(get_filename(s, 1), NULL, none));
		// old_fd == fds[0];
		// fds[0] = open(expand_token(&s[1], NULL, none), O_RDONLY);
		// if (fds[0] == -1)
		// 	printf("file doenst exist\n");
		// else if (old_fd != -1)
		// 	close(old_fd);
	}
	else if (type == 2)
	{
		printf("opening -%s- as append\n", expand_token(get_filename(s, 2), NULL, none));
		// old_fd == fds[1];
		// fds[1] = open(expand_token(&s[2], NULL, none),
		// 		O_APPEND | O_CREAT, 0644);
		// if (fds[1] == -1)
		// 	printf("error while opening file\n");
		// else if (old_fd != -1)
		// 	close(old_fd);
	}
	else if (type == 3)
	{
		printf("opening -%s- as write\n", expand_token(get_filename(s, 1), NULL, none));
		// old_fd == fds[1];
		// fds[1] = open(expand_token(&s[1], NULL, none),
		// 		O_WRONLY | O_TRUNC | O_CREAT, 0644);
		// if (fds[1] == -1)
		// 	printf("error while opening file\n");
		// else if (old_fd != -1)
		// 	close(old_fd);
	}
}

void	get_fds(t_list *tokens, int fds[2])
{
	while (tokens)
	{
		if (tokens->content[0] && (tokens->content[0] == '<'))
		{
			if (ft_strncmp(tokens->content, "<<", 2) == 0)
				open_file(tokens->content, fds, 0);
			else
				open_file(tokens->content, fds, 1);
		}
		else if (tokens->content[0] && tokens->content[0] == '>')
		{
			if (ft_strncmp(tokens->content, ">>", 2) == 0)
				open_file(tokens->content, fds, 2);
			else
				open_file(tokens->content, fds, 3);
		}
		tokens = tokens->next;
	}
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

t_cmd	*get_command(char *s)
{
	t_cmd	*out;
	t_list	*tokens;

	out = ft_push(ft_alloc(sizeof(t_cmd)));
	tokens = get_tokens(s);
	// while (tokens)
	// {
	// 	printf("tokens: %s\n", tokens->content);
	//  	tokens = tokens->next;
	// }
	// printf("\n");
	//out.env = msh_getenv();
	//get_fds(tokens, out->fd);
	out->argv = get_args(tokens);
	out->next = NULL;
	return (out);
}
