/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_history_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:50:38 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/18 14:00:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline t_list	*_match(t_rl_input *i, t_rl_input *s, uint64_t d);
static inline t_list	*getmatch(t_rl_input *i, t_rl_input *s, uint64_t d);
static inline uint8_t	getinput(t_rl_input *s);
static inline void	display(t_rl_input *i, t_rl_input *s);

uint64_t	ft_rl_hist_search(t_rl_input *input, uint64_t direction)
{
	t_rl_input	search;
	t_list		*match;

	if (direction == KEY_UP)
		search = (t_rl_input){.plen = 14,
			.prompt = ft_push(ft_strdup("bck-i-search: ")),
			.cursor = ft_push(ft_calloc(1, sizeof(t_rl_cursor)))};
	else
		search = (t_rl_input){.plen = 14,
			.prompt = ft_push(ft_strdup("fwd-i-search: ")),
			.cursor = ft_push(ft_calloc(1, sizeof(t_rl_cursor)))};
	*search.cursor = (t_rl_cursor){.t_rows = input->cursor->t_rows,
		.t_cols = input->cursor->t_cols, .i_row = input->cursor->row + 1,
		.i_col = 1, .row = input->cursor->row + 1, .col = 1};
	display(input, &search);
	match = _match(input, &search, direction);
	if (match)
		ft_rl_hist_setcurrent(match);
	ft_rl_redisplay(input, LINE);
	return (search.key);
}

static inline t_list	*getmatch(t_rl_input *i, t_rl_input *s, uint64_t d)
{
	static t_list	*pmatch = NULL;
	const t_list	*current = *ft_rl_hist_getcurrent();
	char			*s1;
	char			*s2;

	s1 = ft_push(ft_rl_inputstr(s, 0));
	while (current)
	{
		s2 = ft_rl_inputstr(current->blk, 0);
		if (ft_strnstr(s2, s1, ft_strlen(s2)))
			break ;
		if (d == KEY_UP)
			current = current->next;
		else
			current = current->prev;
	}
	ft_popblk(s1);
	if (pmatch != current && current)
		ft_rl_updateinput(i, current->blk);
	pmatch = (t_list *)current;
	return ((t_list *)current);
}

static inline t_list	*_match(t_rl_input *i, t_rl_input *s, uint64_t d)
{
	t_list		*match;

	match = NULL;
	while (getinput(s))
	{
		match = getmatch(i, s, d);
		if (!match && s->plen == 14)
		{
			ft_popblk(s->prompt);
			s->prompt = ft_push(ft_strjoin("failing-", s->prompt));
			s->plen = 22;
		}
		else if (match && s->plen == 22)
		{
			ft_popblk(s->prompt);
			s->prompt = ft_push(ft_substr(s->prompt, 8, 14));
			s->plen = 14;
		}
		else if (!match || !s->head)
			ft_rl_updateinput(i, (*ft_rl_hist_getcurrent())->blk);
		display(i, s);
	}
	return (match);
}

static inline uint8_t	getinput(t_rl_input *s)
{
	t_rl_fn	f;

	read(0, &s->key, sizeof(s->key));
	if (ft_rl_getcurinput()->sigexit)
		return (0);
	f = ft_rl_getmap(s->key);
	if (f == ft_rl_ins || f == ft_rl_dcr || f == ft_rl_bdc)
		return (ft_rl_execmap(s, s->key));
	return (0);
}

static inline void	display(t_rl_input *i, t_rl_input *s)
{
	ft_rl_eol(i);
	if (i->cursor->row >= s->cursor->i_row)
		*s->cursor = (t_rl_cursor){.i_row = i->cursor->row + 1,
			.i_col = 1, .row = i->cursor->row + 1, .col = 1};
	if (s->cursor->row > i->cursor->t_rows && i->cursor->row > 1)
	{
		ft_rl_term_scroll(KEY_UP, i->cursor);
		s->cursor->i_row--;
	}
	ft_rl_redisplay(i, PROMPT);
	ft_rl_inputcursor(s);
	ft_printf("%s%s%s", TERM_CLEAR_END, s->prompt, ft_rl_inputstr(s, 0));
}
