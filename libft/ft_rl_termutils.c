/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_termutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:44:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 02:10:10 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_rl_movecursor(size_t *i, size_t llen, char c)
{
	if (c == KEY_U_C && *i < llen)
	{
		ft_printf("%s", TERM_CUR_RIGHT);
		*i = *i + 1;
	}
	else if (c == KEY_U_D && *i > 0)
	{
		ft_printf("%s", TERM_CUR_LEFT);
		*i = *i - 1;
	}
}

void	ft_rl_movencursor(size_t n, char dir, size_t *i, size_t llen)
{
	if (dir == KEY_U_C)
	{
		while (n-- && *i < llen)
		{
			ft_printf("%s", TERM_CUR_RIGHT);
			*i = *i + 1;
		}
	}
	else
	{
		while (n-- && *i > 0)
		{
			ft_printf("%s", TERM_CUR_LEFT);
			*i = *i - 1;
		}
	}
}

void	ft_rl_setcurcol(size_t i)
{
	char	*cmd;

	cmd = ft_strjoin("\e[", ft_uitoa(i));
	cmd = ft_strjoin(cmd, "G");
	ft_printf("%s", cmd);
}
