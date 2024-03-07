/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:02:23 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 11:26:31 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_split.c
 */

#include "libft.h"

static size_t	getsplits(char const *s, char c);
static char		*makesplit(char const *s, char c);

/** @brief Splits the string s into substrings of s separated by c
 *
 * Goes through s, allocating a new substring into an array of strings
 * between every every occurence of c in s
 * @param *s Pointer to the string to split
 * @param c Character to split on
 * @retval char ** Pointer to the NULL terminated string array or NULL
 * if one of the allocations failed
 */
char	**ft_split(char const *s, char c)
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

	if (!c)
	{
		if (!*s)
			return (0);
		return (1);
	}
	i = 0;
	splits = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i - 1] != c)
			splits++;
	}
	return (splits);
}

static char	*makesplit(char const *s, char c)
{
	static size_t	i = 0;
	size_t			j;

	while (s[i] && s[i] == c)
		i++;
	j = i;
	while (s[i] && s[i] != c)
		i++;
	if (j == i)
	{
		i = 0;
		return (NULL);
	}
	return (ft_push(ft_substr(s, j, i - j)));
}
