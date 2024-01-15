/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:35:52 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 12:54:59 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_vm.c
 */

#include "libft.h"

/** @brief Initializes and returns a pointer to the virtual memory manager
 *
 * When called for the first time, initializes the virtual memory manager with
 * the defaults.
 * @retval t_vm * Pointer to the virtual memory manager
 */
t_vm	*ft_getvm(void)
{
	static t_vm				vm;
	static unsigned char	init = 0;

	if (!init)
	{
		vm.stacksize = 0;
		vm.maxobjs = GC_START;
		vm.objs = 0;
		vm.head = NULL;
		init = 1;
	}
	return (&vm);
}
