/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:58:58 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/28 15:53:17 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H
# include "libft.h"
# include "ft_rl_keys.h"
# include "ft_rl_term.h"
# include "ft_rl_data.h"
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

// ft_rl_wildcard.c
t_rl_wc		*ft_rl_wildcard_expand(const char *pattern);

// ft_rl_keymap.c
void		ft_rl_map(const char *key, const char *func, t_rl_mapmode mode);
void		ft_rl_unmap(const char *key);

// ft_rl_keymap_utils.c
uint8_t		ft_rl_ismapped(uint64_t key);
t_rl_fn		ft_rl_getmap(uint64_t key);

#endif
