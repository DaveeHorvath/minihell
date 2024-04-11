/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_complete_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:43:29 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/11 14:48:38 by ivalimak         ###   ########.fr       */
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
		len = ft_strlen(ft_rl_complete_basename(completions->blk));
		if (len > llen)
			llen = len;
		completions = completions->next;
		if (completions && !completions->prev)
			break ;
	}
	return (llen);
}

char	*ft_rl_complete_basename(const char *s)
{
	const char	*tmp;

	tmp = ft_strchr(s, '/');
	while (tmp && tmp[1])
	{
		s = tmp + 1;
		tmp = ft_strchr(s, '/');
	}
	return ((char *)s);
}
