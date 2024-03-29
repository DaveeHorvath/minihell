/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:31:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/29 01:27:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline void	joinchar(t_rl_word *curword, uint8_t c);

void	ft_rl_addchar(t_rl_input *input, uint8_t c)
{
	if (!input->head)
	{
		ft_rl_addword(input, c);
		return ;
	}
	if (c != KEY_SPACE)
	{
		if (input->current->wtype == NORMAL)
			joinchar(input->current, c);
		else
			ft_rl_addword(input, c);
	}
	else
	{
		if (input->current->wtype == SPACE)
			joinchar(input->current, c);
		else
			ft_rl_addword(input, c);
	}
}

void	ft_rl_rmchar(t_rl_input *input, uint64_t key)
{
	t_rl_word	*curword;
	char		*newword;

	if (!input->head || (key == KEY_DEL && !input->current->next
			&& input->current->i == input->current->len))
		return ;
	curword = input->current;
	if (key == KEY_BACKSPACE && curword->i == 0)
		curword = curword->prev;
	if (!curword)
		return ;
	if ((key == KEY_BACKSPACE && curword->len == 1)
		|| (key == KEY_DEL && curword->len == 1))
	{
		ft_rl_rmword(input, curword, key);
		return ;
	}
	newword = (ft_calloc(ft_getblksize(curword->word), sizeof(*newword)));
	if (!newword)
		return ;
	ft_popblk(curword->word);
	ft_strlcpy(newword, curword->word, curword->i + (key == KEY_DEL));
	ft_strlcpy(newword + curword->i - 1 + (key == KEY_DEL),
		curword->word + curword->i + (key == KEY_DEL),
		curword->len-- - curword->i + 1 + (key == KEY_DEL));
	curword->word = ft_push(newword);
	curword->i -= (key == KEY_BACKSPACE);
}

uint8_t	ft_rl_getinput(t_rl_input *input)
{
	uint64_t	key;

	key = 0;
	if (read(0, &key, sizeof(key)) < 0)
		return (-1);
	if (ft_rl_ismapped(key))
	{
		ft_rl_dbg_info(input, key);
		return (ft_rl_execmap(input, key));
	}
	if (key == KEY_BACKSPACE || key == KEY_DEL)
		ft_rl_rmchar(input, key);
	else if (key >= KEY_SPACE && key <= KEY_TILDE)
		ft_rl_addchar(input, key);
	ft_rl_redisplay(input, LINE);
	ft_rl_dbg_info(input, key);
	return (1);
}

static inline void	joinchar(t_rl_word *curword, uint8_t c)
{
	char	*newword;

	newword = ft_calloc(ft_getblksize(curword->word) + 1, sizeof(*newword));
	if (!newword)
		return ;
	ft_popblk(curword->word);
	ft_strlcpy(newword, curword->word, curword->i + 1);
	newword[curword->i] = c;
	ft_strlcpy(newword + curword->i + 1, curword->word + curword->i,
		curword->len++ - curword->i + 1);
	curword->word = ft_push(newword);
	curword->i++;
}
