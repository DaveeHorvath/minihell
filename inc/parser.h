/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:30:07 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/18 18:55:15 by dhorvath         ###   ########.fr       */
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
# include <fcntl.h>

# define UNMATCHED_S_QUOTE 1
# define UNMATCHED_D_QUOTE 2
# define UNMATCHED_PARENTHESIES 3
# define WRONG_PARENTHESIES 4
# define SYNTAX_ERROR 5
# define MALLOC_FAIL 6
# define PARENTHESIES_IN_NODE 7
# define PIPELINE_ISSUE 8

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
	int				pipe_end;
	char			*original;
	char			**argv;
	char			**env;
	pid_t			pid;
	struct s_cmd	*next;
	int				exitcode;
}	t_cmd;

t_node		*make_tree(char *s);
int			execute_string(char *s);
t_cmd		*get_command(char *s, char **commands, int *prev_out, int i);
int			update_quote(char c, enum e_quotes *quote);
int			exec_pipeline(char *s);
int			get_fds(t_tokens *tokens, int fds[2]);
int			is_builtin(char *s, int isexpanded);
int			exec_builtin(char *s, int outfd, int actual_exit);
char		**get_args(t_tokens *tokens);
t_tokens	*get_tokens(char *s);
char		**ft_quoted_split(char *s, char c);
void		append(t_tokens **list, char *s);

/* errors */
void		cmd_not_found(t_cmd *cmd);
void		child_error(void);
int			handle_file_error(int start, char *s);
int			parse_error(int error);
int			tree_parse_error(int error, t_node *tree);

/* validity */
int			is_valid(char *s);
int			validate_tree(t_node *tree);

/* signals */
t_cmd		*save_pipeline(t_cmd *_pipline, int set);
void		keyboardinterupt(int sig);

/* files */
int			handle_outfile(t_tokens *tokens, int fds[2]);
int			handle_infile(t_tokens *tokens, int fds[2]);
int			open_file(char *s, int fds[2], int type);

/* handling tokens */
char		*expand_token(char *token, char *content, enum e_quotes quote);
int			handle_quotes(char *s, int i);
int			handle_redirect(char *s, int i, t_tokens **tokens, int start);
int			handle_space(char *s, int i, int *old_i, t_tokens **tokens);
char		*get_filename(char *s, int start);

void		expand_alias(t_tokens **tokens, char *s);
int			expand_wildcards(t_tokens **tokens);

#endif