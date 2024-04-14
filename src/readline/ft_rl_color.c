/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:21:56 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/14 15:22:23 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline char	**gethlp(void);

char	*ft_rl_gethlcolor(void)
{
	return (*gethlp());
}

void	ft_rl_sethlcolor(const char *s)
{
	*gethlp() = (char *)s;
}

static inline char	**gethlp(void)
{
	static char	*hlcolor = NULL;

	return (&hlcolor);
}
