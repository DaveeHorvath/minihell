/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:35:52 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 23:44:13 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_vm.c
 */

#include "lft_gc.h"

/** @brief Initializes and returns a pointer to the virtual memory manager
 *
 * When called for the first time, initializes the virtual memory manager with
 * the defaults.
 * @retval t_vm * Pointer to the virtual memory manager
 */
t_vm	*ft_getvm(void)
{
	static t_vm		vm;
	static uint8_t	init = 0;

	if (!init)
	{
		vm.maxobjs = GC_START;
		init = 1;
	}
	return (&vm);
}
