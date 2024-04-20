/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:57:07 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/20 13:28:40 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_cd(char *path)
{
	char	cwd[MAXPATHLEN];

	if (!path)
		return (1);
	msh_setenv("PWD", getcwd(cwd, MAXPATHLEN));
	if (chdir(path) == -1)
	{
		ft_dprintf(2, "msh: cd: %s: ", path);
		perror(NULL);
		return (1);
	}
	msh_setenv("OLDPWD", msh_getenv("PWD"));
	msh_setenv("PWD", getcwd(cwd, MAXPATHLEN));
	return (0);
}
