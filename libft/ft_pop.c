/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:39:17 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/07 14:38:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_pop.c
 */

#include "libft.h"

/** @brief Pops a block from the vm stack
 *
 * @retval void* Pointer to the popped block
 */
void	*ft_pop(void)
{
	t_vm	*vm;
	void	*out;

	vm = ft_getvm();
	if (vm->stacksize == 0)
	{
		ft_putendl_fd("GC: pop: stack underflow", 2);
		ft_exit(E_STACKUF);
	}
	ft_debugmsg(GCPOP, "Popping block %p", vm->stack[vm->stacksize -1]);
	out = vm->stack[--vm->stacksize];
	vm->stack[vm->stacksize] = NULL;
	return (out);
}

/** @brief Pops all blocks from the vm stack
 */
void	ft_popall(void)
{
	ft_popn(ft_getvm()->stacksize);
}

/** @brief Pops the block blk from the stack, if present
 *
 * @param *blk Address of block to be popped
 */
void	ft_popblk(void *blk)
{
	t_vm	*vm;
	size_t	i;

	if (!blk)
		return ;
	i = 0;
	vm = ft_getvm();
	if (vm->stacksize == 0)
	{
		ft_putendl_fd("GC: pop: stack underflow", 2);
		ft_exit(E_STACKUF);
	}
	while (i < vm->stacksize && vm->stack[i] != blk)
		i++;
	if (i == vm->stacksize)
		return ;
	ft_debugmsg(GCPOP, "Popping block %p from stack index %u", blk, i);
	while (i < vm->stacksize - 1)
	{
		vm->stack[i] = vm->stack[i + 1];
		i++;
	}
	vm->stacksize--;
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
		ft_pop();
		blks--;
	}
}
