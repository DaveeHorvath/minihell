/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_initfuncs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:59:29 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/27 12:49:44 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rl_map_internal.h"

t_rl_func	*ft_rl_newfunc(const char *name, t_rl_fn f)
{
	t_rl_func	*func;

	func = ft_alloc(sizeof(*func));
	if (!func)
		return (NULL);
	ft_memcpy(func, &(t_rl_func){.name = name, .f = f}, sizeof(*func));
	return (func);
}

uint8_t	ft_rl_exit(t_rl_input *input)
{
	(void)input;
	ft_exit(0);
	return (0);
}

void	ft_rl_initfuncs(t_list **funcs)
{
	ft_lstadd_front(funcs, ft_lstnew(ft_rl_newfunc("beginning-of-line",
				ft_rl_sol)));
	ft_lstadd_front(funcs, ft_lstnew(ft_rl_newfunc("end-of-line", ft_rl_eol)));
	ft_lstadd_front(funcs, ft_lstnew(ft_rl_newfunc("forward-char", ft_rl_fwd)));
	ft_lstadd_front(funcs, ft_lstnew(ft_rl_newfunc("backward-char",
				ft_rl_bck)));
	ft_lstadd_front(funcs, ft_lstnew(ft_rl_newfunc("readline-end",
				ft_rl_exit)));
}
