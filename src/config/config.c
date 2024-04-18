/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:48:19 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/17 14:31:14 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void	cfg_export(size_t lnbr, char *line);
static void	cfg_parseline(size_t lnbr, char *line);
static int	cfg_open(const char *cfg_fname);

int	msh_parseconfig(const char *cfg_fname)
{
	int		fd;
	char	*line;
	size_t	lnbr;

	fd = cfg_open(cfg_fname);
	if (fd < 0)
		return (0);
	lnbr = 0;
	line = ft_strtrim(get_next_line(fd), "\t\n\v\f\r ");
	while (line)
	{
		lnbr++;
		if (*line && *line != '#')
			cfg_parseline(lnbr, line);
		line = ft_strtrim(get_next_line(fd), "\t\n\v\f\r ");
	}
	close(fd);
	return (1);
}

static void	cfg_export(size_t lnbr, char *line)
{
	size_t	start;
	size_t	vars;
	char	*var;
	char	*val;

	start = 6;
	while (ft_isspace(line[start]))
		start++;
	vars = cfg_varcount(&line[start]);
	if (!vars || vars > 2)
		cfg_err(lnbr, "export: syntax error");
	else
	{
		var = ft_push(ft_substr(line, start, ft_strclen(&line[start], '=')));
		val = ft_substr(line, ft_strclen(line, '=') + 1, ft_strlen(line));
		val = ft_push(ft_strtrim(val, "'\""));
		msh_setenv(var, val);
	}
}

static void	cfg_parseline(size_t lnbr, char *line)
{
	static void	(*f[1])(size_t lnbr, char *line) = {cfg_export};
	int			type;

	type = cfg_matchkw(line);
	if (type >= 0)
		f[type](lnbr, line);
	else
		cfg_err(lnbr, "unknown keyword");
}

static int	cfg_open(const char *cfg_fname)
{
	const char	*path;

	if (!cfg_fname)
		path = ft_strsjoin(msh_getenv("HOME"), MSHRC, '/');
	else
		path = cfg_fname;
	if (!path)
		return (-1);
	return (open(path, O_RDONLY));
}
