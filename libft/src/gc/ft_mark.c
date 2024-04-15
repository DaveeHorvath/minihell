/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:08:26 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/11 22:48:58 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_mark.c
 */

#include "lft_gc.h"

static inline t_obj	*getobj(const void *blk);

/** @brief Removes a mark from blk
 *
 * @param *blk Pointer to the block to set an not in use
 */
void	ft_unmark(const void *blk)
{
	t_obj	*obj;

	obj = getobj(blk);
	if (obj && obj->marks)
	{
		obj->marks--;
		if (obj->traps)
			obj->traps--;
	}
}

/** @brief Adds a mark to blk
 *
 * @param *blk Pointer to the block to set as in use
 */
void	ft_mark(const void *blk)
{
	static t_vm	*vm = NULL;
	t_obj	*obj;

	if (!vm)
		vm = ft_getvm();
	obj = getobj(blk);
	if (obj)
	{
		obj->marks++;
		if (vm->ptrap)
			obj->traps++;
	}
}

static inline t_obj	*getobj(const void *blk)
{
	static t_vm	*vm = NULL;
	t_obj		*obj;

	if (!vm)
		vm = ft_getvm();
	obj = vm->head;
	while (obj)
	{
		if (obj->blk == blk - sizeof(t_obj *))
			break ;
		obj = obj->next;
	}
	return (obj);
}
