/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:47:38 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/11 09:32:26 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_alloc.c
 */

#include "lft_gc.h"
#include "lft_put.h"

static t_obj	*ft_findblk(size_t n);

/** @brief Returns an allocated block of at least n bytes
 *
 * Tries to find an unused allocated block of at least n bytes.
 * Allocates a new block if no existing block was found
 * @param n Amount of bytes to allocate
 * @retval void* Pointer to the start of the allocated memory
 * or null if the allocation failed
 */
void	*ft_alloc(size_t n)
{
	t_obj			*obj;

	if (!n)
		return (NULL);
	obj = ft_findblk(n);
	if (!obj)
		obj = ft_newobj(n);
	if (!obj)
		return (NULL);
	obj->asize = n;
	return ((void *)obj->blk + sizeof(t_obj *));
}

/** @brief Finds the smallest unused block that is at least n bytes
 *
 * @param n Minimum size for the block
 * @retval t_obj* Pointer to the start of the block or null if none found
 */
static t_obj	*ft_findblk(size_t n)
{
	static t_vm	*vm = NULL;
	t_obj		*obj;
	t_obj		*out;

	if (!vm)
		vm = ft_getvm();
	obj = vm->head;
	out = NULL;
	while (obj)
	{
		if (obj->blksize >= n && !obj->marks)
		{
			if (!out || out->blksize > obj->blksize)
				out = obj;
			if (out->blksize == n)
				break ;
		}
		obj = obj->next;
	}
	if (out)
		ft_debugmsg(GCALLOC, "Found unused obj at %p (%u bytes at %p)", out,
			out->blksize, out->blk);
	return (out);
}
