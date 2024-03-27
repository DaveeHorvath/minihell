/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:46:46 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/27 12:14:22 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RL_MAP_H
# define RL_MAP_H
# include "libft.h"
# include "rl_data.h"
# include "rl_keys.h"
# include "rl_term.h"

// ft_rl_exec.c
uint8_t	ft_rl_execmap(t_rl_input *input, uint64_t key);

// ft_rl_keymap.c
void	ft_rl_map(const char *key, const char *func, t_rl_mapmode mode);
void	ft_rl_unmap(const char *key);

// ft_rl_keymap_utils.c
uint8_t	ft_rl_ismapped(uint64_t key);
t_rl_fn	ft_rl_getmap(uint64_t key);

#endif
