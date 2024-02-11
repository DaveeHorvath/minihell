/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:58:58 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/11 13:16:38 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H
# include "libft.h"
# include "rl_keys.h"
# include "rl_term.h"
# include "rl_data.h"
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

# define RL_METACHAR_SIZE 8

// ft_readline.c
char	*ft_readline(const char *p);

// ft_rl_input.c
void	ft_rl_updateinput(t_rl_input *input, char *newinput);
int		ft_rl_getinput(t_rl_input *input);

// ft_rl_completion.c
void	ft_rl_complete(t_rl_input *input);

// ft_rl_replace.c
void	ft_rl_complete_replace(t_rl_input *input, char *word);
void	ft_rl_complete_display(t_rl_input *input, t_list *completions);

// ft_rl_history.c
char	*ft_rl_history_next(void);
char	*ft_rl_history_prev(void);
void	ft_rl_history_update(char *line);
void	ft_rl_history_commit(char *line);

// ft_rl_historyfile.c
void	ft_rl_history_load(void);
void	ft_rl_history_save(void);

// ft_rl_command.c
int		ft_rl_exec(t_rl_input *input, char c);
int		ft_rl_iscommand(t_rl_input *input, char c);

// ft_rl_altcmds.c
void	ft_rl_altcmd(t_rl_input *input);

// ft_rl_ctrlcmds.c
void	ft_rl_ctrlcmd(t_rl_input *input, char c);

// ft_rl_completionutils.c
t_list	*ft_rl_complete_env(char *word);
t_list	*ft_rl_complete_cmd(char *word);
t_list	*ft_rl_complete_file(char *word);

// ft_rl_historyutils.c
t_list	**ft_rl_history_gethead(void);
t_list	**ft_rl_history_getcurrent(char r);
void	ft_rl_history_setcurrent(t_list *node);
void	ft_rl_history_recycle(void);

// ft_rl_inpututils.c
void	ft_rl_nextword(t_rl_input *input);
void	ft_rl_prevword(t_rl_input *input);

#endif
