/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:05:15 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:19 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *blk)
{
	t_list	*out;

	ft_push(blk);
	out = ft_calloc(1, sizeof(t_list));
	if (blk)
		ft_pop();
	if (!out)
		return (NULL);
	out->blk = blk;
	return (out);
}
