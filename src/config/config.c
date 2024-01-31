/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:48:19 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/31 13:19:35 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void	cfg_alias(size_t lnbr, char *line)
{
	size_t	vars;
	char	*alias;
	char	*cmd;

	line = line + 5;
	while (ft_isspace(*line))
		line++;
	vars = cfg_varcount(line);
	if (vars != 2)
		cfg_err(lnbr, "alias: syntax error");
	else
	{
		alias = line;
		cmd = ft_strchr(line, '=');
		*cmd++ = '\0';
		ft_dprintf(2, "[D] aliased %s as %s\n", cmd, alias);
	}
}

static void	cfg_export(size_t lnbr, char *line)
{
	size_t	vars;
	char	*var;
	char	*val;

	line = line + 6;
	while (ft_isspace(*line))
		line++;
	vars = cfg_varcount(line);
	if (!vars || vars > 2)
		cfg_err(lnbr, "export: syntax error");
	else
	{
		var = line;
		val = ft_strchr(line, '=');
		if (val)
			*val++ = '\0';
		msh_setenv(var, val);
	}
}

static void	cfg_parseline(size_t lnbr, char *line)
{
	static void	(*f[2])(size_t lnbr, char *line) = {cfg_export, cfg_alias};
	int			type;

	type = cfg_matchkw(line);
	if (type >= 0)
		f[type](lnbr, line);
	else if (type == -1)
		cfg_err(lnbr, "unknown keyword");
}

static int	cfg_open(void)
{
	char	*path;

	path = ft_strsjoin(msh_getenv("HOME"), MSHRC, '/');
	if (!path)
		return (-1);
	return (open(path, O_RDONLY));
}

int	parseconfig(void)
{
	int		fd;
	char	*line;
	size_t	lnbr;

	fd = cfg_open();
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
