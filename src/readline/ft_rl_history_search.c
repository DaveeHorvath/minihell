/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_history_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:50:38 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/05 16:28:15 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline uint64_t	match(t_rl_input *i, t_rl_input *s, uint64_t d);
static inline t_list		*getmatch(t_rl_input *i, t_rl_input *s, uint64_t d);
static inline uint8_t		getinput(t_rl_input *s, uint64_t *key);
static inline void		display(t_rl_input *i, t_rl_input *s);

uint8_t	ft_rl_hist_search(t_rl_input *input, uint64_t direction)
{
	t_rl_input	search;
	uint64_t	key;

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
	ft_rl_updatecursor(search.cursor);
	ft_putstr_fd(search.prompt, 1);
	key = match(input, &search, direction);
	ft_rl_redisplay(input, LINE);
	if (ft_rl_ismapped(key) && ft_rl_getmap(key) != ft_rl_rsh
		&& ft_rl_getmap(key) != ft_rl_fsh)
		return (ft_rl_execmap(input, key));
	return (1);
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
	if (pmatch != current)
		ft_rl_updateinput(i, current->blk);
	pmatch = (t_list *)current;
	return ((t_list *)current);
}

static inline uint64_t	match(t_rl_input *i, t_rl_input *s, uint64_t d)
{
	t_list		*match;
	uint64_t	key;

	while (getinput(s, &key))
	{
		match = getmatch(i, s, d);
		if (!match && s->plen == 14)
		{
			ft_popblk((char *)s->prompt);
			s->prompt = ft_push(ft_strjoin("failing-", s->prompt));
			s->plen = 22;
		}
		else if (match && s->plen == 22)
		{
			ft_popblk((char *)s->prompt);
			s->prompt = ft_push(ft_substr(s->prompt, 8, 14));
			s->plen = 14;
		}
		if (!match || !s->head)
			ft_rl_updateinput(i, (*ft_rl_hist_getcurrent())->blk);
		display(i, s);
	}
	return (key);
}

static inline uint8_t	getinput(t_rl_input *s, uint64_t *key)
{
	*key = 0;
	read(0, key, sizeof(*key));
	if (*key == KEY_BACKSPACE && s->head)
		ft_rl_rmchar(s, *key);
	else if (*key >= KEY_SPACE && *key <= KEY_TILDE)
		ft_rl_addchar(s, *key);
	else
		return (0);
	return (1);
}

static inline void	display(t_rl_input *i, t_rl_input *s)
{
	if (i->cursor->row >= s->cursor->i_row)
		*s->cursor = (t_rl_cursor){.i_row = i->cursor->row + 1,
			.i_col = 1, .row = i->cursor->row + 1, .col = 1};
	ft_rl_updatecursor(s->cursor);
	ft_printf("%s%s%s", TERM_CLEAR_END, s->prompt, ft_rl_inputstr(s, 0));
}
