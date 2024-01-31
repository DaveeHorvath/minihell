/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_termutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:44:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/31 20:18:13 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	movecursor(size_t *i)
{
	char	c;

	if (read(0, &c, 1) < 1)
		return ;
	if (c == KEY_U_C)
	{
		ft_printf("%s", TERM_MV_RIGHT);
		*i = *i + 1;
	}
	else if (c == KEY_U_D)
	{
		ft_printf("%s", TERM_MV_LEFT);
		*i = *i - 1;
	}
}

void	ft_rl_setcurcol(size_t i)
{
	while (i)
	{
		ft_printf("%s", TERM_MV_LEFT);
		i--;
	}
}

void	ft_rl_altcmd(size_t *i)
{
	char	c;

	if (read(0, &c, 1) < 1)
		return ;
	if (c == '[')
		movecursor(i);
}

void	ft_rl_ctrlcmd(char c)
{
	(void)c;
	return ;
}
