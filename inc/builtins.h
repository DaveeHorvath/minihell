/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:00:21 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/06 15:17:19 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "env.h"
# include "libft.h"
# include <stdio.h>

# define MAXPATHLEN 1024

// echo
int	msh_echo(char **args, int fd);

// cd
int	msh_cd(char *path);

// pwd
int	msh_pwd(int fd);

// export
int	msh_export(char **args);

// unset
int	msh_unset(char **args);

// env
int	msh_env(int fd);

// exit
int	msh_exit(char **args, int parent);

#endif
