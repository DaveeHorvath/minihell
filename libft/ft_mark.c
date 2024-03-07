/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:08:26 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 23:40:39 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_mark.c
 */

#include "libft.h"

static void	ft_mark(t_vm *vm, t_obj *obj);

/** @brief Unmarks all objects
 *
 * @param *vm Pointer to the virtual memory manager
 */
void	ft_unmarkall(t_vm *vm)
{
	t_obj	*obj;

	obj = vm->head;
	while (obj)
	{
		obj->marked = 0;
		obj = obj->next;
	}
}

/** @brief Marks all objects in use
 *
 * Goes through all objects and marks them as in use if they are found
 * on the vm stack
 * @param *vm Pointer to the virtual memory manager
 */
void	ft_markall(t_vm *vm)
{
	t_obj	*obj;

	obj = vm->head;
	while (obj)
	{
		ft_mark(vm, obj);
		obj = obj->next;
	}
}

/** @brief Marks object if in use
 *
 * Marks the object as in use if it is found
 * on the vm stack
 * @param *vm Pointer to the virtual memory manager
 * @param *obj Pointer to the obj being checked
 */
static void	ft_mark(t_vm *vm, t_obj *obj)
{
	size_t	i;

	i = 0;
	while (obj->marked == 0 && i < vm->stacksize)
	{
		if (obj->blk == vm->stack[i++])
			obj->marked = 1;
	}
}
