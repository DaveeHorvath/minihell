/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:13:14 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/17 17:46:50 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "ft_readline.h"

static int	open_outfile(int fds[2], int type, char *s);
static int	handle_heredoc(int fds[2], char *s);

static int	handle_heredoc(int fds[2], char *s)
{
	const int		hd_fd = open(".hdoc", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	char			*line;
	int				should_stop;

	should_stop = 0;
	heredoc_stopper(&should_stop, 1);
	line = ft_push(ft_readline("> ", OFF));
	while (line && !should_stop)
	{
		if (ft_strequals(s, ft_strtrim(line, "\n")) || should_stop)
			break ;
		ft_putstr_fd(expand_token(line, NULL, none), hd_fd);
		ft_pop();
		line = ft_push(ft_readline("> ", OFF));
	}
	heredoc_stopper(NULL, 1);
	close(hd_fd);
	if (fds[0] != 0)
		close(fds[0]);
	fds[0] = open(".hdoc", O_RDONLY);
	unlink(".hdoc");
	if (fds[0] < 0)
		return (handle_file_error(0, "heredoc"));
	return (0);
}

static int	open_outfile(int fds[2], int type, char *s)
{
	int	old_fd;

	if (type == 2)
	{
		old_fd = fds[1];
		fds[1] = open(expand_token(get_filename(s, 2), NULL, none),
				O_CREAT | O_APPEND | O_WRONLY, 0644);
		if (old_fd != -1 || old_fd != 1)
			close(old_fd);
		if (fds[1] == -1)
			return (handle_file_error(2, s));
	}
	else if (type == 3)
	{
		old_fd = fds[1];
		fds[1] = open(expand_token(get_filename(s, 1), NULL, none),
				O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (old_fd != -1 || old_fd != 1)
			close(old_fd);
		if (fds[1] == -1)
			return (handle_file_error(1, s));
	}
	return (0);
}

int	handle_infile(t_tokens *tokens, int fds[2])
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
	return (1);
}

int	handle_outfile(t_tokens *tokens, int fds[2])
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
	return (1);
}

int	open_file(char *s, int fds[2], int type)
{
	int	old_fd;

	if (type == 0)
	{
		if (handle_heredoc(fds, get_filename(s, 2)) == 1)
			return (1);
	}
	if (type == 1)
	{
		old_fd = fds[0];
		fds[0] = open(expand_token(get_filename(s, 1), NULL, none), O_RDONLY);
		if (fds[0] == -1)
			return (handle_file_error(1, s));
		if (old_fd != -1 || old_fd != 0)
			close(old_fd);
	}
	if (type == 2 || type == 3)
	{
		if (open_outfile(fds, type, s) == 1)
			return (1);
	}
	return (0);
}
