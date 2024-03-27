/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_map_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:00:33 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/26 13:58:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RL_MAP_INTERNAL_H
# define RL_MAP_INTERNAL_H
# include "ft_readline.h"

// ft_rl_initkeys.c
t_rl_key	*ft_rl_newkey(const char *name, const uint64_t value);
void		ft_rl_initkeys(t_list **keys);

// ft_rl_initkeys2.c
void		ft_rl_initkeys5(t_list **keys);

// ft_rl_initkeys3.c
void		ft_rl_initkeys10(t_list **keys);

// ft_rl_initfuncs.c
t_rl_func	*ft_rl_newfunc(const char *name, t_rl_fn f);
void		ft_rl_initfuncs(t_list **funcs);

// ft_rl_keymap_lists.c
t_list		**ft_rl_getkeys(void);
t_list		**ft_rl_getfuncs(void);
t_list		**ft_rl_getkeymaps(void);

#endif
