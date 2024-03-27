/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:58:58 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/27 15:14:03 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H
# include "libft.h"
# include "rl_map.h"
# include "rl_keys.h"
# include "rl_term.h"
# include "rl_data.h"
# include <fcntl.h>
# include <dirent.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/ioctl.h>

# ifndef RL_DEBUG_MSG
#  define RL_DEBUG_MSG 0
# endif

# ifndef RL_HFNAME
#  define RL_HFNAME ".rl_history"
# endif

# ifndef RL_HISTORY_SIZE
#  define RL_HISTORY_SIZE 100
# endif

# define RL_ALTKEY_SIZE 8

// ft_readline.c
char		*ft_readline(const char *prompt);

// ft_rl_init.c
void		ft_rl_init(void);

// ft_rl_input.c
uint8_t		ft_rl_getinput(t_rl_input *input);
void		ft_rl_addchar(t_rl_input *input, uint8_t c);
void		ft_rl_rmchar(t_rl_input *input, uint64_t c);

// ft_rl_word.c
t_rl_word	*ft_rl_splitword(t_rl_word *w1);
t_rl_word	*ft_rl_joinword(t_rl_word *w1, t_rl_word *w2);
void		ft_rl_insertword(t_rl_input *input, t_rl_word *newword);
void		ft_rl_addword(t_rl_input *input, uint8_t c);
void		ft_rl_rmword(t_rl_input *input, uint64_t key);

// ft_rl_move.c
uint8_t		ft_rl_sol(t_rl_input *input);
uint8_t		ft_rl_eol(t_rl_input *input);
uint8_t		ft_rl_fwd(t_rl_input *input);
uint8_t		ft_rl_bck(t_rl_input *input);

// ft_rl_cursor.c
void		ft_rl_shiftcursor(size_t n, uint64_t direction);

// ft_rl_wildcard.c
t_rl_wc		*ft_rl_wildcard_expand(const char *pattern);

// ft_rl_utils.c
void		ft_rl_redisplay(t_rl_input *input, t_rl_rdmode mode);

// ft_rl_termutils.c
t_rl_cursor	*ft_rl_getcursor(t_rl_input *input);
void		ft_rl_updatecursor(t_rl_cursor *cursor);

#endif
