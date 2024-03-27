/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:50:39 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/27 12:49:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rl_map_internal.h"

static inline void	ft_rl_defaultbinds(void);

void	ft_rl_init(void)
{
	static uint8_t	init = 0;

	if (init)
		return ;
	ft_rl_initkeys(ft_rl_getkeys());
	ft_rl_initfuncs(ft_rl_getfuncs());
	ft_rl_defaultbinds();
	init = 1;
}

static inline void	ft_rl_defaultbinds(void)
{
	ft_rl_map("<C-a>", "beginning-of-line", QREMAP);
	ft_rl_map("<C-e>", "end-of-line", QREMAP);
	ft_rl_map("<left>", "backward-char", QREMAP);
	ft_rl_map("<right>", "forward-char", QREMAP);
	ft_rl_map("<C-d>", "readline-end", QREMAP);
}
