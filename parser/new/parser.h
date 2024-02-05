/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:30:07 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/05 16:57:00 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* 
	Self contained, not leaking parser, 
	call it from separate fork for exit code

	For the base part my pipex was good enough,
	but took inspiration from @ivalimak for linked lists

	The AST idea is thanks to @hseppane
*/

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	left;
	struct s_node	right;
	char			*content;
}	t_node;

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

t_node	make_tree(char *s);
int		execute_string(char *s);
/* utility functions */
int		isspace(char c);

#endif