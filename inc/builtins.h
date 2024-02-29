/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:00:21 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/29 18:37:24 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "env.h"
# include "libft.h"

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
