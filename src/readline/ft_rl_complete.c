/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_complete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:18:26 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/10 13:41:40 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline uint8_t	complete_mult(t_rl_input *input, t_list *completions);
static inline t_list	*completew(t_rl_word *w);
static inline void		display(t_rl_input *input, t_list *completions);

uint8_t	ft_rl_complete(t_rl_input *input)
{
	t_list	*completions;
	uint8_t	rv;

	if (!input->head)
		return (1);
	rv = 1;
	completions = completew(input->current);
	if (!completions)
		input->current->i = input->current->len;
	else if (!completions->next)
		ft_rl_replaceword(input, ft_rl_strword(completions->blk));
	else
		rv = complete_mult(input, completions);
	ft_rl_redisplay(input, LINE);
	return (rv);
}

static inline uint8_t	complete_mult(t_rl_input *input, t_list *completions)
{
	display(input, completions);
	return (1);
}

static inline t_list	*completew(t_rl_word *w)
{
	t_list	*completions;

	if (*w->word == '$')
		completions = ft_rl_complete_env(w->word + 1);
	else if (w->wtype == NORMAL)
		completions = ft_rl_complete_file(w->word);
	else
		completions = ft_rl_complete_file("");
	if (completions && completions->next)
		ft_rl_complete_inc(completions, w->word + (*w->word == '$'));
	return (completions);
}

static inline void	display(t_rl_input *input, t_list *completions)
{
	(void)input;
	while (completions)
	{
		ft_dprintf(2, "'%s'\n");
		completions = completions->next;
	}
}
