/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:57:07 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/23 17:32:43 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char	*getnewpath(char *newpath);
static char	*getnextdir(char **path);
static int	diradd(char **path, char *dir);

int	msh_cd(char *path)
{
	if (!path)
		return (0);
	chdir(path);
	msh_setenv("OLDPWD", msh_getenv("PWD"));
	if (*path == '/')
		msh_setenv("PWD", path);
	else
		msh_setenv("PWD", getnewpath(path));
	return (1);
}

static char	*getnewpath(char *newpath)
{
	char	*path;

	path = ft_strdup(msh_getenv("PWD"));
	if (!path)
		return (NULL);
	while (*newpath)
	{
		if (!diradd(&path, getnextdir(&newpath)))
			return (NULL);
	}
	return (path);
}

static char	*getnextdir(char **path)
{
	size_t	i;
	char	*dir;

	i = 0;
	dir = *path;
	while (dir[i] && dir[i] != '/')
		i++;
	dir = ft_substr(*path, 0, i);
	if (!dir)
		return (NULL);
	*path = *path + ft_strlen(dir);
	if (**path == '/')
		*path = *path + 1;
	return (dir);
}

static int	diradd(char **path, char *dir)
{
	if (!dir)
		return (0);
	if (!ft_strncmp(dir, ".", 2))
		return (1);
	if (!ft_strncmp(dir, "..", 3))
		*ft_strrchr(*path, '/') = '\0';
	else
		*path = ft_strsjoin(*path, dir, '/');
	if (!(*path))
		return (0);
	return (1);
}
