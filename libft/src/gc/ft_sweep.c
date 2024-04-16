/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sweep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:14:57 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/10 22:37:29 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_sweep.c
 */

#include "lft_gc.h"
#include "lft_put.h"

/** @brief Frees all unmarked objects
 *
 * Goes through all allocated blocks, freeing them if they haven't
 * been marked as in use
 * @param *vm Pointer to the virtual memory manager
 */
void	ft_sweep(t_vm *vm)
{
	t_obj	**obj;
	t_obj	*tmp;

	obj = &vm->head;
	while (*obj)
	{
		if (!(*obj)->marks)
		{
			tmp = *obj;
			*obj = tmp->next;
			vm->objs--;
			ft_debugmsg(GCSWEEP, "Freeing unused block at %p", tmp->blk);
			ft_debugmsg(GCSWEEP, "Freeing unused obj at %p", tmp);
			free((void *)tmp->blk);
			free(tmp);
		}
		else
			obj = &(*obj)->next;
	}
}
