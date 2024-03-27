/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_keymap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:58:06 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/27 12:34:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rl_map_internal.h"

static inline uint8_t	checkremap(const char *key, t_rl_mapmode mode);
static inline void	createmap(uint64_t key, t_rl_fn f);
static inline void	printerr(char *key, char *func, void *keys, void *funcs);

void	ft_rl_map(const char *key, const char *func, t_rl_mapmode mode)
{
	t_list	*keys;
	t_list	*funcs;

	if (!checkremap(key, mode))
		return ;
	keys = *ft_rl_getkeys();
	funcs = *ft_rl_getfuncs();
	while (keys)
	{
		if (ft_strequals(key, ((t_rl_key *)keys->blk)->name))
			break ;
		keys = keys->next;
	}
	while (funcs)
	{
		if (ft_strequals(func, ((t_rl_func *)funcs->blk)->name))
			break ;
		funcs = funcs->next;
	}
	if (keys && funcs)
		createmap(((t_rl_key *)keys->blk)->value,
			((t_rl_func *)funcs->blk)->f);
	else
		printerr((char *)key, (char *)func, keys, funcs);
}

void	ft_rl_unmap(const char *key)
{
	t_list		*keys;
	t_list		*keymaps;
	uint64_t	keyval;

	keys = *ft_rl_getkeys();
	while (keys)
	{
		if (ft_strequals(((t_rl_key *)keys->blk)->name, key))
			break ;
		keys = keys->next;
	}
	if (!keys)
	{
		printerr((char *)key, NULL, keys, NULL);
		return ;
	}
	keyval = ((t_rl_key *)keys->blk)->value;
	keymaps = *ft_rl_getkeymaps();
	while (keymaps)
	{
		if (((t_rl_map *)keymaps->blk)->key == keyval)
			break ;
		keymaps = keymaps->next;
	}
	ft_lstrmnode(ft_rl_getkeymaps(), keymaps);
}

static inline uint8_t	checkremap(const char *key, t_rl_mapmode mode)
{
	t_list		*keys;

	keys = *ft_rl_getkeys();
	while (keys)
	{
		if (ft_strequals(((t_rl_key *)keys->blk)->name, key))
			break ;
		keys = keys->next;
	}
	if (!keys || !ft_rl_ismapped(((t_rl_key *)keys->blk)->value))
		return (1);
	if (mode == WARN)
		ft_dprintf(2, "ft_readline: key %s is already mapped\n", key);
	else if (mode == REMAP)
		ft_dprintf(2, "ft_readline: remapping key %s\n", key);
	if (mode == WARN || mode == QUIET)
		return (0);
	ft_rl_unmap(key);
	return (1);
}

static inline void	createmap(uint64_t key, t_rl_fn f)
{
	t_rl_map	*map;

	map = ft_alloc(sizeof(*map));
	if (!map)
		return ;
	ft_memcpy(map, &(t_rl_map){.f = f, .key = key}, sizeof(*map));
	ft_lstadd_back(ft_rl_getkeymaps(), ft_lstnew(map));
}

static inline void	printerr(char *key, char *func, void *keys, void *funcs)
{
	if (!keys && key)
		ft_dprintf(2, "ft_readline: unrecognized key: %s\n", key);
	if (!funcs && func)
		ft_dprintf(2, "ft_readline: unrecognized function: %s\n", func);
}
