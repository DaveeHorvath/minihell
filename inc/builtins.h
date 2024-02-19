/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:00:21 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/23 16:56:01 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "env.h"
# include "libft.h"

// echo
void	msh_echo(char *s, char nl);

// cd
int		msh_cd(char *path);

// pwd
void	msh_pwd(void);

// export
void	msh_export(char *variable);

// unset
void	msh_unset(char *var);

// env
void	msh_env(void);

// exit
void	msh_exit(int estatus);

#endif
