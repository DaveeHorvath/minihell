/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:48:19 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/25 12:14:02 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

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
		{
			execute_string(ft_push(line));
			ft_popblk(line);
		}
		line = ft_strtrim(get_next_line(fd), "\t\n\v\f\r ");
	}
	close(fd);
	return (1);
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
