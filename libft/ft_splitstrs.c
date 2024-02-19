/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitstrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:02:23 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:25 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_splitstrs.c
 */

#include "libft.h"

static size_t	getsplits(char const *s, char c);
static size_t	getstrend(char const *s, size_t i, const char c);
static char		*makesplit(char const *s, char c);

/** @brief Splits the string s into substrings of s separated by c
 *
 * Behaves like ft_split, but doesn't split if it encounters c
 * between a pair of quotes
 * @param *s Pointer to the string to split
 * @param c Character to split on
 * @retval char ** Pointer to the NULL terminated string array or NULL
 * if one of the allocations failed
 */
char	**ft_splitstrs(char const *s, char c)
{
	char	**out;
	size_t	splits;
	size_t	i;

	if (!s)
		return (NULL);
	splits = getsplits(s, c);
	ft_push((void *)s);
	out = ft_calloc((splits + 1), sizeof(char *));
	ft_pop();
	ft_push(out);
	if (!out)
		return (NULL);
	i = 0;
	while (i <= splits)
	{
		out[i++] = makesplit(s, c);
		if (!out[i - 1] && i <= splits)
			return (NULL);
	}
	ft_popn(i);
	return (out);
}

static size_t	getsplits(char const *s, char c)
{
	size_t	i;
	size_t	splits;

	if (!c && !*s)
		return (0);
	i = 0;
	splits = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
		{
			i = getstrend(s, i + 1, s[i]);
			splits++;
			continue ;
		}
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c
			&& s[i] != '\'' && s[i] != '"')
			i++;
		if (s[i - 1] != c)
			splits++;
	}
	return (splits);
}

static size_t	getstrend(char const *s, size_t i, const char c)
{
	while (s[i] && (s[i] != c || s[i - 1] == '\\'))
		i++;
	if (s[i])
		i++;
	return (i);
}

static char	*makesplit(char const *s, char c)
{
	static size_t	i = 0;
	size_t			j;

	if (s[i] == '\'' || s[i] == '"')
	{
		j = i + 1;
		i = getstrend(s, i + 1, s[i]);
		return (ft_push(ft_strremove(ft_substr(s, j, i - 1 - j), '\\')));
	}
	while (s[i] && s[i] == c)
		i++;
	j = i;
	if (s[i] == '\'' || s[i] == '"')
		return (makesplit(s, c));
	while (s[i] && s[i] != c)
		i++;
	if (j == i)
	{
		i = 0;
		return (NULL);
	}
	return (ft_push(ft_substr(s, j, i - j)));
}
