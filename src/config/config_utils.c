/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:04:19 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/31 13:23:52 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static char	*skipquotes(char *line, char end)
{
	line++;
	while (*line != end)
		line++;
	return (line);
}

size_t	cfg_varcount(char *line)
{
	size_t	vars;

	if (!*line)
		return (0);
	vars = 1;
	while (*line)
	{
		if (*line == '\'' || *line == '"')
		{
			line = skipquotes(line, *line);
		}
		if (!*line)
			return (0);
		if (*line == '=' || ft_isspace(*line))
			vars++;
		line++;
	}
	return (vars);
}

void	cfg_err(size_t lnbr, char *msg)
{
	ft_dprintf(2, "~/%s: line %u: %s\n", MSHRC, lnbr, msg);
}

int	cfg_matchkw(char *line)
{
	if (!ft_strncmp(line, "export", 6))
	{
		if (line[6] && !ft_isspace(line[6]))
			return (-1);
		return (0);
	}
	else if (!ft_strncmp(line, "alias", 5))
	{
		if (line[5] && !ft_isspace(line[5]))
			return (-1);
		return (1);
	}
	return (-1);
}
