/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_match.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:01:37 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/24 17:03:17 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "ft_readline.h"

static void	matchfiles(char *pat, char *path, int cmd, t_list **completions);
static int	iscmd(char *path, char *cmd);

t_list	*ft_rl_complete_env(char *pat)
{
	size_t		patlen;
	t_list		*completions;
	extern char	**environ;
	char		*var;

	completions = NULL;
	while (*pat == '$')
		pat++;
	patlen = ft_strlen(pat);
	while (*environ)
	{
		var = ft_substr(*environ, 0, ft_strclen(*environ, '='));
		if (!var)
		{
			ft_lstpopall(completions);
			return (NULL);
		}
		if (!ft_strncmp(var, pat, patlen))
			ft_lstadd_back(&completions, ft_lstnew(ft_strjoin("$", var)));
		environ++;
	}
	return (completions);
}

t_list	*ft_rl_complete_cmd(char *pat)
{
	t_list	*completions;
	char	**path;

	path = ft_pusharr(ft_split(msh_getenv("PATH"), ':'));
	if (!path)
		return (NULL);
	completions = NULL;
	while (*path)
	{
		matchfiles(pat, *path, 1, &completions);
		ft_popblk(*path++);
	}
	ft_popblk(path);
	matchfiles(pat, ".", 1, &completions);
	return (completions);
}

t_list	*ft_rl_complete_file(char *pat)
{
	t_list	*completions;
	char	*path;

	completions = NULL;
	path = ft_strrchr(pat, '/');
	if (path)
	{
		path = ft_substr(pat, 0, path - pat);
		if (ft_strequals(path, ""))
			path = ft_strdup("/");
		pat = ft_strrchr(pat, '/') + 1;
	}
	matchfiles(pat, ft_push(path), 0, &completions);
	ft_rl_complete_checkdirs(path, completions);
	ft_popblk(path);
	return (completions);
}

static void	matchfiles(char *pat, char *path, int cmd, t_list **completions)
{
	DIR				*dir;
	struct dirent	*data;
	size_t			patlen;

	if (path)
		dir = opendir(path);
	else
		dir = opendir(".");
	if (!dir)
		return ;
	data = readdir(dir);
	patlen = ft_strlen(pat);
	while (data)
	{
		if (!ft_strequals(data->d_name, ".")
			&& !ft_strequals(data->d_name, "..")
			&& !ft_strncmp(data->d_name, pat, patlen))
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
