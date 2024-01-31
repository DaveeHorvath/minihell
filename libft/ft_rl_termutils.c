/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_termutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:44:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/01 00:05:26 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	movecursor(size_t *i, size_t llen)
{
	char	c;

	if (read(0, &c, 1) < 1)
		return ;
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

static void	movencursor(size_t n, char dir, size_t *i, size_t llen)
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

void	ft_rl_altcmd(size_t *i, char *p, char *line)
{
	char	c;

	if (read(0, &c, 1) < 1)
		return ;
	if (c == '[')
		movecursor(i, ft_strlen(line));
	else if (c == KEY_F)
		ft_rl_nextword(i, line, ft_strlen(p));
	else if (c == KEY_B)
		ft_rl_lastword(i, line, ft_strlen(p));
}

void	ft_rl_ctrlcmd(char c, size_t *i, char *p, char *line)
{
	if (c == KEY_C_A)
	{
		ft_rl_setcurcol(ft_strlen(p) + 1);
		*i = 0;
	}
	else if (c == KEY_C_E)
	{
		ft_rl_setcurcol(ft_strlen(p) + ft_strlen(line) + 1);
		*i = ft_strlen(line);
	}
	else if (c == KEY_C_F)
		movencursor(1, KEY_U_C, i, ft_strlen(line));
	else if (c == KEY_C_B)
		movencursor(1, KEY_U_D, i, ft_strlen(line));
	else if (c == KEY_C_L && line)
		ft_printf("%s%s%s%s", TERM_CLEAR_SCREEN, TERM_CUR_RESET, p, line);
	else if (c == KEY_C_L)
		ft_printf("%s%s%s", TERM_CLEAR_SCREEN, TERM_CUR_RESET, p);
}
