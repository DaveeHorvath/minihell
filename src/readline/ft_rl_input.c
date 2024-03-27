/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:31:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/27 16:11:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static inline void	joinchar(t_rl_word *curword, uint8_t c);
static inline void	ft_rl_dbg_info(t_rl_input *input, uint64_t key);

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

	if (!input->head)
		return ;
	curword = input->current;
	if ((key == KEY_BACKSPACE && curword->len == 1)
		|| (key == KEY_DEL && curword->i == curword->len))
	{
		ft_rl_rmword(input, key);
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
	if (RL_DEBUG_MSG)
		ft_rl_dbg_info(input, key);
	if (ft_rl_ismapped(key))
		return (ft_rl_execmap(input, key));
	if (key == KEY_BACKSPACE || key == KEY_DEL)
	{
		ft_rl_rmchar(input, key);
	}
	else if (key >= KEY_SPACE && key <= KEY_TILDE)
	{
		ft_rl_addchar(input, key);
		ft_rl_shiftcursor(1, KEY_RIGHT);
	}
	ft_rl_redisplay(input, LINE);
	ft_rl_updatecursor(input->cursor);
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

static inline void	ft_rl_dbg_info(t_rl_input *input, uint64_t key)
{
	ft_dprintf(2, "curpos: %d;%d\n", input->cursor->row, input->cursor->col);
	ft_dprintf(2, "curnode: %p\n", input->current);
	if (input->current)
		ft_dprintf(2, "curnode->word: [%s][%u]\n", input->current->word,
				input->current->i);
	if (ft_rl_ismapped(key))
		ft_dprintf(2, "key %X mapped to %p\n", key, ft_rl_getmap(key));
	else
		ft_dprintf(2, "key %X not mapped\n", key);
}
