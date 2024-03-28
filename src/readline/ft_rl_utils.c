/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:24:54 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/28 17:38:55 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

t_rl_input	*ft_rl_dupinput(t_rl_input *input)
{
	t_rl_input	*out;

	if (!input)
		return (NULL);
	out = ft_push(ft_calloc(1, sizeof(*out)));
	*out = (t_rl_input){.plen = input->plen, .prompt = input->prompt,
		.cursor = input->cursor};
	out->head = ft_rl_dupwords(input->head);
	return (out);
}

t_rl_word	*ft_rl_dupwords(t_rl_word *words)
{
	t_rl_word	*head;
	t_rl_word	*word;

	head = NULL;
	while (words)
	{
		if (!head)
			word = ft_push(ft_calloc(1, sizeof(*word)));
		else
		{
			word->next = ft_push(ft_calloc(1, sizeof(*word)));
			if (word->next)
				word->next->prev = word;
			word = word->next;
		}
		if (!word)
			return (NULL);
		*word = (t_rl_word){.i = words->len, .len = words->len,
			.wtype = words->wtype, .word = ft_push(ft_strdup(words->word))};
		if (!word->word)
			return (NULL);
		if (!head)
			head = word;
	}
	return (head);
}

char	*ft_rl_inputstr(t_rl_input *input)
{
	char		*out;
	t_rl_word	*w;

	if (!input)
		return (NULL);
	w = input->head;
	out = NULL;
	while (w)
	{
		ft_strjoin(out, w->word);
		ft_popblks(2, w, w->word);
		w = w->next;
	}
	ft_popblk(input);
	return (out);
}

void	ft_rl_redisplay(t_rl_input *input, t_rl_rdmode mode)
{
	t_rl_word	*w;

	if (mode == ALL)
		ft_printf("%s%s", TERM_CUR_RESET, TERM_CLEAR_END);
	else if (mode == LINE)
		ft_printf("%s%s", TERM_CUR_SOL, TERM_CLEAR_END);
	else
		ft_printf("%s", TERM_CLEAR_END);
	w = input->current;
	if (mode != CURRENT)
	{
		ft_putstr_fd(input->prompt, 1);
		w = input->head;
	}
	while (w)
	{
		if (mode != CURRENT)
			ft_putstr_fd(w->word, 1);
		else
			ft_putstr_fd(&w->word[w->i], 1);
		w = w->next;
	}
	ft_rl_resetcursor(input);
}
