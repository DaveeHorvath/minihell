/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:30:07 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/26 14:24:18 by dhorvath         ###   ########.fr       */
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
#include <fcntl.h>

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

typedef struct s_tokens
{
	char			*content;
	struct s_tokens	*next;
}	t_tokens;

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

/* errors */
void	cmd_not_found(t_cmd *cmd);
void	child_error(void);
int	handle_file_error(int start, char *s);

/* files */
int	handle_outfile(t_tokens *tokens, int fds[2]);
int	handle_infile(t_tokens *tokens, int fds[2]);
int	open_file(char *s, int fds[2], int type);

/* handling tokens */
char	*expand_token(char *token, char *content, enum e_quotes quote);
int		handle_quotes(char *s, int i);
int		handle_redirect(char *s, int i, t_tokens **tokens, int start);
int		handle_space(char *s, int i, int *old_i, t_tokens **tokens);
char	*get_filename(char *s, int start);

#endif