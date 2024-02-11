/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_completionutils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:09:33 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/11 20:11:15 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

size_t	ft_rl_complete_getlongest(t_list *completions)
{
	size_t	maxlen;
	size_t	len;

	maxlen = 0;
	while (completions)
	{
		len = ft_strlen(completions->blk);
		if (len > maxlen)
			maxlen = len;
		completions = completions->next;
	}
	return (maxlen);
}
