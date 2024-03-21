/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:57:07 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/21 22:19:43 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_cd(char *path)
{
	char	cwd[MAXPATHLEN];

	if (!path)
		path = msh_getenv("HOME");
	if (!path)
		return (1);
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
