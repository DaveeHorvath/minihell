/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:11:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/22 17:33:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H
# include "libft.h"
# include "prompt.h"
# include "environment.h"
# define E_MALLOC 1
# define E_READLINE 2
# define E_PIPE 3
# define E_FORK 4
# define E_DUP 5
# define E_EXEC 127

typedef struct s_cmd
{
	int				fd[2];
	char			wait;
	char			**argv;
	char			**env;
	pid_t			pid;
	struct s_cmd	*next;
}	t_cmd;

#endif
