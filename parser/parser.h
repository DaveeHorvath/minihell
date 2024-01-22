/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:30:07 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/22 23:39:11 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_cmd
{
	int				fd[2];
	char			**argv;
	char			**env;
	pid_t			pid;
	struct s_cmd	*next;
}	t_cmd;


#endif