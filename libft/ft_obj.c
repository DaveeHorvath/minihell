/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:47:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/17 22:50:06 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_obj.c
 */

#include "libft.h"

/** @brief Allocates and initializes a new t_obj
 *
 * Allocates a new t_obj, adding it to the start of the object list
 * with a obj->blk of n bytes
 * @param *vm Pointer to the virtual memory manager
 * @param n Amount of bytes to allocate for obj->blk
 * @retval t_obj* Pointer to the new object or NULL if
 * the allocation failed
 */
t_obj	*ft_newobj(t_vm *vm, size_t n)
{
	t_obj	*obj;

	if (vm->objs == vm->maxobjs)
		ft_clean();
	obj = malloc(sizeof(t_obj));
	if (!obj)
		return (NULL);
	ft_debugmsg(GCALLOC, "Allocated new obj at %p", obj);
	obj->marked = 0;
	obj->next = vm->head;
	vm->head = obj;
	obj->blk = malloc(n);
	if (!obj->blk)
		return (NULL);
	ft_debugmsg(GCALLOC, "Allocated new block at %p (%u bytes)", obj->blk, n);
	obj->blksize = n;
	vm->objs++;
	return (obj);
}

/** @brief Finds and returns the obj containing blk
 *
 * @param *blk Pointer to the block of the object to find
 * @retval t_obj* Pointer to the object that contains *blk, or NULL
 * if no obj contains blk
 */
t_obj	*ft_getobj(void *blk)
{
	t_obj	*obj;

	if (!blk)
		return (NULL);
	ft_debugmsg(GCOBJ, "Looking for an object with block %p", blk);
	obj = ft_getvm()->head;
	while (obj)
	{
		if (obj->blk == blk)
			break ;
		obj = obj->next;
	}
	if (obj)
		ft_debugmsg(GCOBJ, "Found object at %p", obj);
	else
		ft_debugmsg(GCOBJ, "No object found");
	return (obj);
}

/** @brief Registers a non ft_allocced block with the garbage collector
 *
 * Allocates a new obj to hold blk. Due to blk being already allocated
 * the allocation size is set to 0, regardless of the actual size of blk
 * @param *blk Pointer to the block to be registered
 * @retval void* Pointer to blk or NULL if the allocation failed
 */
void	*ft_register(void *blk)
{
	t_obj	*obj;
	t_vm	*vm;

	vm = ft_getvm();
	if (vm->objs == vm->maxobjs)
		ft_clean();
	obj = malloc(sizeof(t_obj));
	if (!obj)
		return (NULL);
	ft_debugmsg(GCALLOC, "Allocated new obj at %p", obj);
	obj->marked = 0;
	obj->next = vm->head;
	vm->head = obj;
	obj->blk = blk;
	ft_debugmsg(GCALLOC, "Registered new block at %p", obj->blk);
	obj->blksize = 0;
	vm->objs++;
	return (obj->blk);
}
