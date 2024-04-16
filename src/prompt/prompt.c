/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:06:49 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/07 14:43:02 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static char	*expandformat(const char *cmd, char **out);
static char	*gethname(const char trunc);
static char	*getdir(const char type, size_t depth);
static char	*truncdir(const char *path, size_t depth);

char	*msh_prompt(const char *p)
{
	char	*out;

	if (!p)
		return (NULL);
	out = NULL;
	while (*p)
	{
		if (*p != '%')
		{
			out = ft_strjoin(out, ft_substr(p, 0, ft_strclen(p, '%')));
			p += ft_strclen(p, '%');
		}
		else if (out)
		{
			ft_push(out);
			p = expandformat(p + 1, &out);
			ft_pop();
		}
		else
			p = expandformat(p + 1, &out);
	}
	return (out);
}

static char	*expandformat(const char *cmd, char **out)
{
	size_t	depth;

	if (*cmd == 'F' || *cmd == 'K' || *cmd == 'B' || *cmd == 'U')
		return (chcolor(cmd + 1, *cmd, out));
	else if (*cmd == 'f' || *cmd == 'k' || *cmd == 'b' || *cmd == 'u')
		return (chcolor(cmd + 1, *cmd, out));
	if (*cmd == 'R')
		*out = ft_strjoin(*out, SGR_RESET);
	else if (*cmd == '%')
		*out = ft_strjoin(*out, "%");
	else if (*cmd == 'n')
		*out = ft_strjoin(*out, msh_getenv("USER"));
	else if (*cmd == 'M')
		*out = ft_strjoin(*out, gethname(0));
	else if (*cmd == 'm')
		*out = ft_strjoin(*out, gethname(1));
	else if (*cmd == 'd' || *cmd == '/' || *cmd == '~' || ft_isdigit(*cmd))
	{
		depth = ft_atoi(cmd);
		while (ft_isdigit(*cmd))
			cmd++;
		*out = ft_strjoin(*out, getdir(*cmd, depth));
	}
	return ((char *)cmd + 1);
}

static char	*gethname(const char trunc)
{
	char	*out;
	int		pfd[2];

	pipe(pfd);
	if (fork() == 0)
	{
		dup2(pfd[1], 1);
		close(pfd[1]);
		close(pfd[0]);
		execve("/usr/bin/uname", ft_split("uname -n", ' '), NULL);
		exit(127);
	}
	close(pfd[1]);
	out = ft_strtrim(get_next_line(pfd[0]), "\n");
	close(pfd[0]);
	if (out && trunc && ft_strrchr(out, '.'))
		*ft_strchr(out, '.') = '\0';
	return (out);
}

static char	*getdir(const char type, size_t depth)
{
	size_t	homelen;
	char	*home;
	char	*out;

	out = msh_getenv("PWD");
	if (ft_strequals(out, "/"))
		return (out);
	if (type == '~')
	{
		home = msh_getenv("HOME");
		homelen = ft_strlen(home);
		if (!ft_strncmp(out, home, homelen))
		{
			if (ft_strlen(out) > homelen)
				out = ft_strjoin("~", ft_substr(out, homelen, ft_strlen(out)));
			else
				out = ft_strdup("~");
		}
	}
	if (depth > 0)
		return (truncdir(out, depth));
	return (out);
}

static char	*truncdir(const char *path, size_t depth)
{
	size_t	i;
	size_t	dirs;

	i = 0;
	dirs = 0;
	while (path[i])
	{
		if (path[i++] == '/')
			dirs++;
	}
	i = 0;
	while (dirs >= depth && i <= dirs - depth)
	{
		path = ft_strchr(path, '/') + 1;
		i++;
	}
	return ((char *)path);
}
