/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:13:14 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/20 16:08:38 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static int	handle_heredoc(int fds[2], char *s)
{
	int		hd_fd;
	char	*line;

	hd_fd = open(".heredoc", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	ft_printf("> ");
	line = ft_push(get_next_line(0));
	while (line)
	{
		if (ft_strequals(s, ft_strtrim(line, "\n")))
		{
			ft_pop();
			break ;
		}
		ft_putstr_fd(expand_token(line, NULL, none), hd_fd);
		ft_pop();
		ft_printf("> ");
		line = ft_push(get_next_line(0));
	}
	close(hd_fd);
	fds[0] = open(".heredoc", O_RDONLY);
	unlink(".heredoc");
	if (fds[0] < 0)
		return (handle_file_error(1, "heredoc"));
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
		if (old_fd != -1)
			close(old_fd);
		if (fds[1] == -1)
			return (handle_file_error(2, s));
	}
	else if (type == 3)
	{
		old_fd = fds[1];
		fds[1] = open(expand_token(get_filename(s, 1), NULL, none),
				O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (old_fd != -1)
			close(old_fd);
		if (fds[1] == -1)
			return (handle_file_error(1, s));
	}
	return (0);
}

static int	handle_infile(t_tokens *tokens, int fds[2])
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

static int	handle_outfile(t_tokens *tokens, int fds[2])
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
		if (old_fd != -1)
			close(old_fd);
	}
	if (type == 2 || type == 3)
	{
		if (open_outfile(fds, type, s) == 1)
			return (1);
	}
	return (0);
}
