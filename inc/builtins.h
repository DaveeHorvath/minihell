/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:00:21 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/27 15:51:25 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUILTINS_H
# define BUILTINS_H
# include "env.h"
# include "libft.h"

// echo
int	msh_echo(char *s, char nl);

// cd
int		msh_cd(char *path);

// pwd
int		msh_pwd(void);

// export
int		msh_export(char *variable);

// unset
int		msh_unset(char *var);

// env
int		msh_env(void);

// exit
int		msh_exit(int estatus);

#endif
