/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:37:38 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/22 23:42:22 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	skip_til(char *s, char c)
{
	int	i;

	while (s[i] && s[i] != c)
		i++;
	return (i);
}

t_list	*parse_pipeline(char *s)
{
	t_list	*commands;
	int		i;
	int		old_i;

	i = 0;
	old_i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			i += skip_til(&s[i], s[i]);
			if (!s[i])
				return (0);
		}
		else if (s[i] == '|')
		{
			if (!append(&commands, s, old_i, i))
				return (clean());
			old_i = i + 1;
		}
		i++;
	}
	if (!append(&commands, s, old_i, i))
		return (clean());
	return (commands);
}
