/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 08:38:24 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/02 12:09:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_rl_wc	*expand_path(char **patterns, size_t depth);
static void		matchpatterns(t_rl_wc *current, t_rl_wc *prev, size_t depth);
static void		matchpattern(char *pattern, char *path, t_list **mtc, char any);
static int		checkpattern(char *pattern, char *name);

t_rl_wc	*ft_rl_wildcard_expand(char *pattern)
{
	t_rl_wc	*matches;
	size_t	depth;
	char	*tmp;

	tmp = pattern;
	depth = 0;
	tmp = ft_strchr(tmp, '/');
	while (tmp)
	{
		tmp++;
		if (*tmp && tmp - 1 != pattern)
			depth++;
		tmp = ft_strchr(tmp, '/');
	}
	matches = expand_path(ft_pusharr(ft_split(pattern, '/')), depth);
	ft_rl_wildcard_rmdot(matches);
	return (matches);
}

static t_rl_wc	*expand_path(char **patterns, size_t depth)
{
	size_t	i;
	t_rl_wc	*prev;
	t_rl_wc	*current;

	prev = NULL;
	current = ft_push(ft_calloc(1, sizeof(t_rl_wc)));
	if (ft_rl_wildcard_checkalloc(current, prev, patterns))
		return (NULL);
	i = 0;
	current->pattern = patterns[i++];
	matchpattern(current->pattern, ".", &current->matches, !depth);
	while (--depth + 1)
	{
		prev = current;
		current = ft_push(ft_calloc(1, sizeof(t_rl_wc)));
		if (ft_rl_wildcard_checkalloc(current, prev, patterns))
			return (NULL);
		current->pattern = patterns[i++];
		matchpatterns(current, prev, depth);
		ft_rl_wildcard_pop(prev);
	}
	ft_popblk(patterns);
	return (current);
}

static void	matchpatterns(t_rl_wc *current, t_rl_wc *prev, size_t depth)
{
	while (prev->matches)
	{
		matchpattern(current->pattern, prev->matches->blk,
			&current->matches, !depth);
		if (!prev->matches->next)
			break ;
		prev->matches = prev->matches->next;
	}
}

static void	matchpattern(char *pattern, char *path, t_list **mtc, char any)
{
	DIR				*dir;
	struct dirent	*data;

	dir = opendir(path);
	if (!dir)
		return ;
	data = readdir(dir);
	while (data)
	{
		if ((!ft_strequals(data->d_name, ".")
				&& !ft_strequals(data->d_name, ".."))
			|| ft_strequals(data->d_name, pattern))
		{
			if (checkpattern(pattern, data->d_name) && (any
					|| ft_rl_isdir(ft_strsjoin(path, data->d_name, '/'))))
				ft_lstadd_back(mtc, ft_lstnew(ft_strsjoin(path,
							data->d_name, '/')));
		}
		data = readdir(dir);
	}
	closedir(dir);
}

static int	checkpattern(char *pattern, char *name)
{
	char	**substrings;

	if ((*name == '.' && *pattern != '.')
		|| (*pattern != '*'
			&& ft_strncmp(name, pattern, ft_strclen(pattern, '*'))))
		return (0);
	substrings = ft_split(pattern, '*');
	if (!substrings)
		return (0);
	if (*pattern == '*')
		name++;
	while (*substrings)
	{
		name = ft_strnstr(name, *substrings, ft_strlen(name));
		if (!name)
			return (0);
		name += ft_strlen(*substrings++);
	}
	if (*name && pattern[ft_strlen(pattern) - 1] != '*')
		return (0);
	return (1);
}
