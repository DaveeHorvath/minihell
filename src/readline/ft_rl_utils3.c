/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:37:42 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/14 15:26:40 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline size_t	*getmlen(void);

size_t	ft_rl_getinputmaxlen(void)
{
	return (*getmlen());
}

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

void	ft_rl_setinputmaxlen(size_t maxlen)
{
	*getmlen() = maxlen;
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

static inline size_t	*getmlen(void)
{
	static size_t	maxlen = 0;

	return (&maxlen);
}
