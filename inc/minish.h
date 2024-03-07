/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:11:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/02 13:03:47 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H
# include "env.h"
# include "config.h"
# include "libft.h"
# include "prompt.h"
# include "parser.h"
# include "builtins.h"
# include "ft_readline.h"
# define E_MALLOC 1
# define E_READLINE 2
# define E_PIPE 3
# define E_FORK 4
# define E_DUP 5
# define E_EXEC 127

// utils.c
void	msh_quit(int estatus);
int		msh_return(int rval);

/* signal handling */
#include <signal.h>

#endif
