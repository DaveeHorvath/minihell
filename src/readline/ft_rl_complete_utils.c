/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_complete_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:43:29 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/10 13:46:25 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

size_t	ft_rl_complete_getlongest(t_list *completions)
{
	size_t	llen;
	size_t	len;

	llen = 0;
	while (completions)
	{
		len = ft_strlen(completions->blk);
		if (len > llen)
			llen = len;
		completions = completions->next;
	}
	return (llen);
}
