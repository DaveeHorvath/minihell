/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:47:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/11 22:30:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_obj.c
 */

#include "lft_gc.h"
#include "lft_put.h"

/** @brief Allocates and initializes a new t_obj
 *
 * Allocates a new t_obj, adding it to the start of the object list
 * with an obj->blk of n bytes
 * @param *vm Pointer to the virtual memory manager
 * @param n Amount of bytes to allocate for obj->blk
 * @retval t_obj* Pointer to the new object or NULL if
 * the allocation failed
 */
t_obj	*ft_newobj(size_t n)
{
	static t_vm	*vm = NULL;
	t_obj		*obj;

	if (!vm)
		vm = ft_getvm();
	if (vm->objs == vm->maxobjs)
		ft_clean();
	obj = malloc(sizeof(*obj));
	if (!obj)
		return (NULL);
	ft_debugmsg(GCALLOC, "Allocated new obj at %p", obj);
	*obj = (t_obj){.marks = 0, .traps = 0, .next = vm->head, .blksize = n,};
	obj->blk = malloc(n + sizeof(*obj));
	if (!obj->blk)
		return (NULL);
	vm->head = obj;
	*(t_obj **)obj->blk = obj;
	ft_debugmsg(GCALLOC, "Allocated new block at %p (%u bytes)", obj->blk, n);
	vm->objs++;
	return (obj);
}

/** @brief Returns a pointer to the obj containing blk
 *
 * @param *blk Pointer to the block
 * @retval t_obj* Pointer to the object that contains *blk
 */
t_obj	*ft_getobj(const void *blk)
{
	if (!blk)
		return (NULL);
	return (*(t_obj **)(blk - sizeof(t_obj *)));
}
