/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_lineutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:29:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 02:10:10 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_rl_nextword(size_t *i, char *line, size_t plen)
{
	size_t	j;

	j = *i;
	if (ft_isspace(line[j]))
	{
		while (ft_isspace(line[j]))
			j++;
	}
	else
	{
		while (line[j] && !ft_isspace(line[j]))
			j++;
		while (ft_isspace(line[j]))
			j++;
	}
	ft_rl_setcurcol(j + plen + 1);
	*i = j;
}

void	ft_rl_prevword(size_t *i, char *line, size_t plen)
{
	size_t	j;

	j = *i;
	if (!line[j] && j > 1)
		j--;
	if (j > 0 && ft_isspace(line[j - 1]))
		j--;
	while (j > 0 && ft_isspace(line[j]))
		j--;
	while (j > 0 && !ft_isspace(line[j - 1]))
		j--;
	ft_rl_setcurcol(j + plen + 2 - (!j));
	*i = j;
}
