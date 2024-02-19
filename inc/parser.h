/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:30:07 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/19 21:15:04 by dhorvath         ###   ########.fr       */
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

enum e_quotes
{
	none,
	doublequote,
	singlequote,
};


typedef struct s_node
{
	struct s_node	*left;
	struct s_node	*right;
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
	int				exitcode;
}	t_cmd;

t_node	*make_tree(char *s);
int		execute_string(char *s);
t_cmd	*get_command(char *s, char **commands, int *prev_out, int i);
int		update_quote(char c, enum e_quotes *quote);
int		exec_pipeline(char *s);

void	do_cmd(t_cmd *cmd);

/* errors */
void	cmd_not_found(t_cmd *cmd);
void	child_error(void);

/* handling tokens */
char	*expand_token(char *token, char *content, enum e_quotes quote);
int		handle_quotes(char *s, int i);
int		handle_redirect(char *s, int i, t_list **tokens, int start);
int		handle_space(char *s, int i, int *old_i, t_list **tokens);

#endif