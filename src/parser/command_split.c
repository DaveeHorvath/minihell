/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:31:25 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/06 15:37:50 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	skip_quotes(char *s, int *i)
{
	char	quote;

	quote = s[*i];
	while (s[*i] && s[*i] != quote)
		(*i)++;
	(*i)++;
}

int	count_splits(char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			skip_quotes(s, &i);
		else if (s[i] == c)
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_quoted_split(char *s, char c)
{
	int		i;
	int		old_i;
	int		current;
	char	**res;

	res = ft_push(ft_calloc(count_splits(s, c) + 2, sizeof(char *)));
	i = 0;
	old_i = 0;
	current = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			skip_quotes(s, &i);
		else
		{
			if (s[i] == c)
			{
				res[current++] = ft_push(ft_substr(s, old_i, i - old_i - 1));
				old_i = i + 1;
			}
			i++;
		}
	}
	res[current] = ft_push(ft_substr(s, old_i, i));
	return (res);
}
