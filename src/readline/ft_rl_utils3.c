/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:37:42 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/14 13:19:06 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline char	**gethlp(void);

size_t	ft_rl_getinputlen(t_rl_input *input)
{
	size_t		len;
	t_rl_word	*w;

	len = 0;
	w = input->head;
	while (w)
	{
		len += w->len;
		w = w->next;
	}
	return (len);
}

void	ft_rl_resize_hook(t_rl_input *input)
{
	t_rl_cursor	*cursor;

	cursor = input->cursor;
	ft_printf("\e[99999;99999H");
	ft_rl_getcurpos(&cursor->t_rows, &cursor->t_cols);
	cursor->i_row = cursor->p_row;
	cursor->i_col = cursor->p_col + input->plen;
	while (cursor->i_col > cursor->t_cols)
	{
		cursor->i_row++;
		cursor->i_col -= cursor->t_cols;
	}
	ft_rl_redisplay(input, PROMPT);
}

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
