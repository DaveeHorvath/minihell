/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_match.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:01:37 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/18 16:18:59 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "ft_readline.h"

static void	matchfiles(char *pattern, char *path, int cmd, t_list **completions);
static int	iscmd(char *path, char *cmd);

t_list	*ft_rl_complete_env(char *pattern)
{
	size_t		patternlen;
	t_list		*completions;
	extern char	**environ;
	char		*var;

	completions = NULL;
	while (*pattern == '$')
		pattern++;
	patternlen = ft_strlen(pattern);
	while (*environ)
	{
		var = ft_substr(*environ, 0, ft_strclen(*environ, '='));
		if (!var)
		{
			ft_lstpopall(completions);
			return (NULL);
		}
		if (!ft_strncmp(var, pattern, patternlen))
			ft_lstadd_back(&completions, ft_lstnew(ft_strjoin("$", var)));
		environ++;
	}
	return (completions);
}

t_list	*ft_rl_complete_cmd(char *pattern)
{
	t_list	*completions;
	char	**path;

	path = ft_pusharr(ft_split(msh_getenv("PATH"), ':'));
	if (!path)
		return (NULL);
	completions = NULL;
	while (*path)
	{
		matchfiles(pattern, *path, 1, &completions);
		ft_popblk(*path++);
	}
	ft_popblk(path);
	matchfiles(pattern, ".", 1, &completions);
	return (completions);
}

t_list	*ft_rl_complete_file(char *pattern)
{
	t_list	*completions;
	char	*path;

	completions = NULL;
	path = ft_strrchr(pattern, '/');
	if (path)
	{
		path = ft_substr(pattern, 0, path - pattern);
		if (ft_strequals(path, ""))
			path = ft_strdup("/");
		pattern = ft_strrchr(pattern, '/') + 1;
	}
	matchfiles(pattern, ft_push(path), 0, &completions);
	ft_rl_complete_checkdirs(path, completions);
	ft_popblk(path);
	return (completions);
}

static void	matchfiles(char *pattern, char *path, int cmd, t_list **completions)
{
	DIR				*dir;
	struct dirent	*data;
	size_t			patternlen;

	if (path)
		dir = opendir(path);
	else
		dir = opendir(".");
	if (!dir)
		return ;
	data = readdir(dir);
	patternlen = ft_strlen(pattern);
	while (data)
	{
		if (!ft_strequals(data->d_name, ".")
			&& !ft_strequals(data->d_name, "..")
			&& !ft_strncmp(data->d_name, pattern, patternlen))
		{
			if (!cmd || iscmd(path, data->d_name))
				ft_lstadd_back(completions, ft_lstnew(ft_strdup(data->d_name)));
		}
		data = readdir(dir);
	}
	closedir(dir);
}

static int	iscmd(char *path, char *cmd)
{
	char	*cmdpath;

	cmdpath = ft_strsjoin(path, cmd, '/');
	if (!cmdpath)
		return (0);
	if (!access(cmdpath, X_OK))
		return (1);
	return (0);
}
