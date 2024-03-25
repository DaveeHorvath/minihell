/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:08:26 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/24 22:26:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_mark.c
 */

#include "lft_gc.h"

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
	t_stack	*stack;

	stack = vm->stack;
	while (!obj->marked && stack)
	{
		if (obj->blk + sizeof(t_obj *) == stack->blk)
			obj->marked = 1;
		stack = stack->next;
	}
}
