/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:18:50 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 20:18:12 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_gc.h"
#include "lft_mem.h"
#include "lft_str.h"
#include "lft_hmap_internal.h"

static inline t_hmap_pair	*_newpair(const char *key, const void *val);
static inline uint8_t	_replace(t_hmap *hmap, t_hmap_pair *pair, size_t i);
static inline void	*_dupval(const void *val);

uint8_t	ft_mapadd(t_hmap *hmap, const char *key, const void *val)
{
	t_hmap_pair	*pair;
	t_hmap_pair	*cur;
	size_t		i;
	size_t		j;

	if (!hmap)
		return (0);
	if ((hmap->count * 100) / hmap->size > 70 && !growmap(hmap))
		return (0);
	pair = _newpair(key, val);
	if (!pair)
		return (0);
	j = 0;
	i = gethash(key, hmap->size, j++);
	cur = hmap->items[i];
	while (cur && cur != HMAP_DEL)
	{
		if (_replace(hmap, pair, i))
			return (1);
		i = gethash(key, hmap->size, j++);
		cur = hmap->items[i];
	}
	hmap->items[i] = pair;
	hmap->count++;
	return (1);
}

static inline t_hmap_pair	*_newpair(const char *key, const void *val)
{
	t_hmap_pair	*pair;

	if (!key)
		return (NULL);
	ft_pushn(2, key, val);
	pair = ft_push(ft_calloc(1, sizeof(*pair)));
	ft_popblks(2, key, val);
	if (!pair)
		return (NULL);
	pair->key = ft_push(ft_strdup(key));
	if (val)
		pair->value = ft_push(_dupval(val));
	else
		pair->value = NULL;
	ft_popblks(2 + (val != NULL), pair, pair->key, pair->value);
	if (!pair->key || !pair->value)
		return (NULL);
	ft_pushn(2 + (val != NULL), pair, pair->key, pair->value);
	return (pair);
}

static inline uint8_t	_replace(t_hmap *hmap, t_hmap_pair *pair, size_t i)
{
	if (ft_strequals(hmap->items[i]->key, pair->key))
	{
		ft_mappop(hmap->items[i]);
		hmap->items[i] = pair;
		return (1);
	}
	return (0);
}

static inline void	*_dupval(const void *val)
{
	size_t		vsize;
	void		*out;

	vsize = ft_getblksize(val);
	out = ft_alloc(vsize);
	if (!out)
		return (NULL);
	return (ft_memcpy(out, val, vsize));
}
