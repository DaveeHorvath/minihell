/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:06:49 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/16 23:24:18 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static char	*printcmd(const char *cmd);
static char	*gethname(const char trunc);
static char	*getdir(const char type, size_t depth);
static char	*truncdir(const char *path, size_t depth);

void	prompt(const char *p)
{
	if (!p)
		return ;
	while (*p)
	{
		if (*p != '%')
			p = p + ft_printf("%.*s", ft_strclen(p, '%'), p);
		else
			p = printcmd(p + 1);
	}
}

static char	*printcmd(const char *cmd)
{
	size_t	depth;

	if (*cmd == 'F' || *cmd == 'K' || *cmd == 'B' || *cmd == 'U')
		return (chcolor(cmd + 1, *cmd));
	else if (*cmd == 'f' || *cmd == 'k' || *cmd == 'b' || *cmd == 'u')
		return (chcolor(cmd + 1, *cmd));
	if (*cmd == 'R')
		ft_printf("%s", RESET);
	else if (*cmd == '%')
		ft_printf("%%");
	else if (*cmd == 'n')
		ft_printf("%s", getenv("USER"));
	else if (*cmd == 'M')
		ft_printf("%s", gethname(0));
	else if (*cmd == 'm')
		ft_printf("%s", gethname(1));
	else if (*cmd == 'd' || *cmd == 'D' || ft_isdigit(*cmd))
	{
		depth = ft_atoi(cmd);
		while (ft_isdigit(*cmd))
			cmd++;
		ft_printf("%s", getdir(*cmd, depth));
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
	char	*home;
	char	*out;
	char	*dir;

	dir = getenv("PWD");
	out = dir;
	if (type == '~')
	{
		home = getenv("HOME");
		if (!ft_strncmp(dir, home, ft_strlen(home)))
		{
			out = ft_strdup(out) + ft_strlen(home) - 1;
			*out = '~';
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
