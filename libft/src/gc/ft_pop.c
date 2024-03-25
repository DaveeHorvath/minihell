/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:39:17 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/24 19:56:03 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_pop.c
 */

#include "lft_gc.h"
#include "lft_put.h"

/** @brief Pops a block from the vm stack
 *
 * @retval void * Pointer to the popped block
 */
void	*ft_pop(void)
{
	static t_vm	*vm = NULL;
	t_stack		*stack;
	void		*blk;

	if (!vm)
		vm = ft_getvm();
	stack = vm->stack;
	if (!stack)
		return (NULL);
	blk = stack->blk;
	ft_stackrm(stack);
	ft_debugmsg(GCPOP, "Popping block %p", blk);
	return (blk);
}

/** @brief Pops all blocks from the vm stack
 */
void	ft_popall(void)
{
	while (ft_pop())
		;
}

/** @brief Pops the block blk from the stack, if present
 *
 * @param *blk Address of block to be popped
 */
void	ft_popblk(void *blk)
{
	static t_vm	*vm = NULL;
	t_stack		*stack;

	if (!vm)
		vm = ft_getvm();
	stack = vm->stack;
	if (!stack || !blk)
		return ;
	while (stack && stack->blk != blk)
		stack = stack->next;
	if (!stack)
		return ;
	ft_stackrm(stack);
	ft_debugmsg(GCPOP, "Popping block %p", blk);
}

/** @brief Pops all the blocks given from the stack
 *
 * @param blks Amount of blocks to pop
 * @param ... Blocks to pop
 */
void	ft_popblks(size_t blks, ...)
{
	va_list	args;

	va_start(args, blks);
	while (blks)
	{
		ft_popblk(va_arg(args, void *));
		blks--;
	}
	va_end(args);
}

/** @brief Pops blks amount of blocks from the vm stack
 *
 * @param blks Amount of blocks to pop
 */
void	ft_popn(size_t blks)
{
	while (blks)
	{
		if (!ft_pop())
			break ;
		blks--;
	}
}
