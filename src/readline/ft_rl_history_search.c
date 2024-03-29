/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_history_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:50:38 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/29 13:06:16 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline t_rl_input	*getmatch(t_rl_input *s, uint64_t d);
static inline uint64_t	match(t_rl_input *i, t_rl_input *s, uint64_t d);
static inline uint8_t		getinput(t_rl_input *s, uint64_t *key);
static inline void		display(t_rl_input *i, t_rl_input *s, uint8_t found);

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

static inline t_rl_input	*getmatch(t_rl_input *s, uint64_t d)
{
	const t_list		*current = *ft_rl_hist_getcurrent();
	char				*s1;
	char				*s2;

	s1 = ft_push(ft_rl_inputstr(s, 0));
	while (current)
	{
		s2 = ft_rl_inputstr(((t_rl_input *)current->blk), 0);
		if (ft_strnstr(s2, s1, ft_strlen(s2)))
		{
			ft_popblk(s1);
			return (current->blk);
		}
		if (d == KEY_UP)
			current = current->next;
		else
			current = current->prev;
	}
	ft_popblk(s1);
	return (NULL);
}

static inline uint64_t	match(t_rl_input *i, t_rl_input *s, uint64_t d)
{
	t_rl_input	*match;
	uint64_t	key;

	while (getinput(s, &key))
	{
		match = getmatch(s, d);
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
		if (match && s->head)
			ft_rl_updateinput(i, match);
		else if (!s->head)
			ft_rl_updateinput(i, (*ft_rl_hist_getcurrent())->blk);
		display(i, s, (match != NULL));
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

static inline void	display(t_rl_input *i, t_rl_input *s, uint8_t found)
{
	size_t	uline[2];
	char	*match;
	char	*out;

	ft_rl_sol(i);
	ft_putstr_fd(TERM_CLEAR_END, 1);
	out = ft_push(ft_rl_inputstr(i, 0));
	match = ft_push(ft_rl_inputstr(s, 0));
	if (found)
	{
		uline[0] = ft_strnstr(out, match, ft_strlen(out)) - out;
		uline[1] = uline[0] + ft_strlen(match);
		ft_printf("%.*s%s%.*s%s%s", uline[0], out, SGR_ULINEON,
				uline[1] - uline[0], &out[uline[0]], SGR_ULINEOFF, 
				&out[uline[1]]);
	}
	else
		ft_putstr_fd(out, 1);
	ft_rl_eol(i);
	if (i->cursor->row >= s->cursor->i_row)
		*s->cursor = (t_rl_cursor){.i_row = i->cursor->row + 1,
			.i_col = 1, .row = i->cursor->row + 1, .col = 1};
	ft_rl_updatecursor(s->cursor);
	ft_printf("%s%s", s->prompt, match);
	ft_popblks(2, match, out);
}
