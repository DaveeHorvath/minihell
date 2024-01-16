/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:06:49 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/15 14:11:13 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static char	*printcmd(const char *cmd);
static char	*chcolor(const char *code, const char type);

void	prompt(const char *p)
{
	if (!p)
		return ;
	while (*p)
	{
		if (*p != '%')
			p = p + ft_printf("%.*s", ft_strclen(p, '%'), p);
		else
			p = printcmd(p + 1);
	}
}

static char	*printcmd(const char *cmd)
{
	if (*cmd == 'f' || *cmd == 'b')
		return (chcolor(cmd + 1, *cmd));
	if (*cmd == 'R')
		ft_printf("%s", RESET);
	else if (*cmd == 'B')
		ft_printf("%s", BOLD);
	else if (*cmd == 'U')
		ft_printf("%s", ULINE);
	else if (*cmd == '%')
		ft_printf("%%");
	return ((char *)cmd + 1);
}

static char	*chcolor(const char *code, const char type)
{
	const static char	fg[8][6] = {FG0, FG1, FG2, FG3, FG4, FG5, FG6, FG7};
	const static char	bg[8][6] = {BG0, BG1, BG2, BG3, BG4, BG5, BG6, BG7};

	if (type == 'f')
		ft_printf("%s", fg[*code - '0']);
	else
		ft_printf("%s", bg[*code - '0']);
	return ((char *)code + 1);
}
