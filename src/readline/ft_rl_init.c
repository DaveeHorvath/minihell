/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:50:39 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/29 12:36:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline void	ft_rl_defaultbinds(void);

void	ft_rl_init(void)
{
	static uint8_t	init = 0;

	if (init)
		return ;
	ft_rl_hist_load(RL_HFNAME);
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
	ft_rl_map("<C-b>", "backward-char", QREMAP);
	ft_rl_map("<C-f>", "forward-char", QREMAP);
	ft_rl_map("<M-b>", "backward-word", QREMAP);
	ft_rl_map("<M-f>", "forward-word", QREMAP);
	ft_rl_map("<C-l>", "clear-screen", QREMAP);
	ft_rl_map("<RET>", "accept-line", QREMAP);
	ft_rl_map("<C-d>", "end-of-file", QREMAP);
	ft_rl_map("<C-p>", "previous-history", QREMAP);
	ft_rl_map("<C-n>", "next-history", QREMAP);
	ft_rl_map("<up>", "previous-history", QREMAP);
	ft_rl_map("<down>", "next-history", QREMAP);
	ft_rl_map("<M-<>", "beginning-of-history", QREMAP);
	ft_rl_map("<M->>", "end-of-history", QREMAP);
	ft_rl_map("<C-r>", "reverse-search-history", QREMAP);
	ft_rl_map("<C-s>", "forward-search-history", QREMAP);
	ft_rl_map("<HME>", "rl-dbg-print-input", QREMAP);
}
