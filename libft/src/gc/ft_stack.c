/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:33:19 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/10 22:36:44 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_stack.c
 */

#include "lft_gc.h"

/** @brief Removes node from the stack
 *
 * @param *node Pointer to the node to remove
 */
void	ft_stackrm(t_stack *node)
{
	static t_vm	*vm = NULL;

	if (!vm)
		vm = ft_getvm();
	if (node->prev)
		node->prev->next = node->next;
	else
		vm->stack = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
}

/** @brief Adds blk to the gc stack
 *
 * @param *blk Pointer to the block to add to the stack
 */
void	ft_stackadd(const void *blk)
{
	static t_vm	*vm = NULL;
	t_stack		*node;

	if (!vm)
		vm = ft_getvm();
	node = malloc(sizeof(*node));
	if (!node)
		return ;
	*node = (t_stack){.blk = blk, .next = vm->stack, .prev = NULL};
	if (vm->stack)
		vm->stack->prev = node;
	vm->stack = node;
}
