/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_ctrlcmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:25:37 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/05 14:04:55 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rl_ctrlcmd(char c, size_t *i, char *p, char **line)
{
	if (c == KEY_C_A)
	{
		ft_rl_setcurcol(ft_strlen(p) + 1);
		*i = 0;
	}
	else if (c == KEY_C_E)
	{
		ft_rl_setcurcol(ft_strlen(p) + ft_strlen(*line) + 1);
		*i = ft_strlen(*line);
	}
	else if (c == KEY_C_F)
		ft_rl_movencursor(1, KEY_U_C, i, ft_strlen(*line));
	else if (c == KEY_C_B)
		ft_rl_movencursor(1, KEY_U_D, i, ft_strlen(*line));
	else if (c == KEY_C_L && *line)
		ft_printf("%s%s%s%s", TERM_CLEAR_SCREEN, TERM_CUR_RESET, p, *line);
	else if (c == KEY_C_L)
		ft_printf("%s%s%s", TERM_CLEAR_SCREEN, TERM_CUR_RESET, p);
	else if (c == KEY_C_P)
		*line = ft_rl_history_next();
	else if (c == KEY_C_N)
		*line = ft_rl_history_prev();
}
