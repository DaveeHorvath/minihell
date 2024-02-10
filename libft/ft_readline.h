/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:58:58 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 02:14:03 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H
# include "libft.h"
# include "rl_keys.h"
# include "rl_term.h"
# include <fcntl.h>
# include <dirent.h>
# include <termios.h>
# include <sys/ioctl.h>

# ifndef RLHFNAME
#  define RLHFNAME ".rl_history"
# endif

# ifndef RL_HISTORY_SIZE
#  define RL_HISTORY_SIZE 100
# endif

// ft_readline.c
char	*ft_readline(const char *p);

// ft_rl_completion.c
void	ft_rl_complete(size_t *i, size_t plen, char **line);

// ft_rl_replace.c
void	ft_rl_complete_replace(size_t *i, char **line, char *word);
void	ft_rl_complete_display(size_t *i, char **line, t_list *completions);

// ft_rl_history.c
char	*ft_rl_history_next(void);
char	*ft_rl_history_prev(void);
void	ft_rl_history_update(char *line);
void	ft_rl_history_commit(char *line);

// ft_rl_historyfile.c
void	ft_rl_history_load(void);
void	ft_rl_history_save(void);

// ft_rl_altcmds.c
void	ft_rl_altcmd(size_t *i, char *p, char **line);

// ft_rl_ctrlcmds.c
void	ft_rl_ctrlcmd(char c, size_t *i, char *p, char **line);

// ft_rl_completionutils.c
t_list	*ft_rl_complete_env(char *word);
t_list	*ft_rl_complete_cmd(char *word);
t_list	*ft_rl_complete_file(char *word);

// ft_rl_historyutils.c
t_list	**ft_rl_history_gethead(void);
t_list	**ft_rl_history_getcurrent(char r);
void	ft_rl_history_setcurrent(t_list *node);
void	ft_rl_history_recycle(void);

// ft_rl_lineutils.c
void	ft_rl_nextword(size_t *i, char *line, size_t plen);
void	ft_rl_prevword(size_t *i, char *line, size_t plen);

// ft_rl_termutils.c
void	ft_rl_movecursor(size_t *i, size_t llen, char c);
void	ft_rl_movencursor(size_t n, char dir, size_t *i, size_t llen);
void	ft_rl_setcurcol(size_t i);

# endif
