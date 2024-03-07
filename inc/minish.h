/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:11:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/07 14:25:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H
# include "env.h"
# include "alias.h"
# include "libft.h"
# include "config.h"
# include "prompt.h"
# include "parser.h"
# include "builtins.h"
# include "ft_readline.h"
# include <signal.h>
# define E_MALLOC 1
# define E_READLINE 2
# define E_PIPE 3
# define E_FORK 4
# define E_DUP 5
# define E_ARGS 6
# define E_EXEC 127

typedef struct s_msh_opts
{
	const char	*cfg_fname;
}	t_msh_opts;

// utils.c
void	msh_quit(int estatus);
int		msh_return(int rval);

#endif
