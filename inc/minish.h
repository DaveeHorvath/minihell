/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:11:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/17 16:46:00 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H
# include "env.h"
# include "libft.h"
# include "config.h"
# include "prompt.h"
# include "parser.h"
# include "errcodes.h"
# include "builtins.h"
# include "ft_readline.h"
# include <signal.h>

// utils.c
void	msh_quit(int estatus);
int		msh_return(int rval);

#endif
