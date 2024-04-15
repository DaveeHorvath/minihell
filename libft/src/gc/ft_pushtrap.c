/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushtrap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 22:22:36 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/13 12:26:19 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_pushtrap.c
 */

#include "lft_gc.h"
#include "lft_put.h"

static inline void	ptrap_pop(t_vm *vm);
static inline void	ptrap_clean(void);

/** @brief Returns the current status of pushtrap
 *
 * @retval uint8_t Current status
 */
uint8_t	ft_pushtrap_status(void)
{
	static t_vm	*vm = NULL;

	if (!vm)
		vm = ft_getvm();
	if (vm->ptrap == 1)
		return (PTRAP_ENABLE);
	return (PTRAP_DISABLE);
}

/** @brief Manages pushtrap settings
 *
 * @param op Operation(s) to execute
 */
void	ft_pushtrap(uint8_t op)
{
	static t_vm	*vm = NULL;

	if (op & PTRAP_ENABLE && op & PTRAP_DISABLE)
		return ;
	if (!vm)
		vm = ft_getvm();
	if (op & PTRAP_ENABLE)
	{
		if (vm->ptrap != 1)
			ft_debugmsg(GCTRAP, "Trap activated");
		vm->ptrap = 1;
	}
	if (op & PTRAP_DISABLE)
	{
		if (vm->ptrap != 0)
			ft_debugmsg(GCTRAP, "Trap deactivated");
		vm->ptrap = 0;
	}
	if (op & PTRAP_POP)
		ptrap_pop(vm);
	if (op & PTRAP_CLEAN)
		ptrap_clean();
}

static inline void	ptrap_pop(t_vm *vm)
{
	t_obj	*obj;

	obj = vm->head;
	ft_debugmsg(GCTRAP, "Popping trapped blocks");
	while (obj)
	{
		while (obj->traps)
			ft_popblk(obj->blk + sizeof(t_obj *));
		obj = obj->next;
	}
}

static inline void	ptrap_clean(void)
{
	ft_debugmsg(GCTRAP, "Starting clean");
	ft_clean();
}
