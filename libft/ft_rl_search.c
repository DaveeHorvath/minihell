/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:27:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/16 20:21:44 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_list	*forwardsearch(t_rl_input *input, t_rl_input *search, t_list *initial);
static t_list	*backwardsearch(t_rl_input *input, t_rl_input *search, t_list *initial);
static void		displaymatch(t_rl_input *input, t_rl_input *search, t_list *current, int *ipos);
static void		updateprompt(t_rl_input *search, char *newprompt);

void	ft_rl_history_search(t_rl_input *input, char direction)
{
	int			row;
	int			col;
	t_list		*initial;
	t_list		*current;
	t_rl_input	search;

	current = *ft_rl_history_getcurrent(0);
	if ((direction == KEY_DOWN && !current->prev)
		|| (direction == KEY_UP && !current->next))
		return ;
	initial = current;
	ft_rl_term_cur_getpos(&row, &col, 0);
	ft_bzero(&search, sizeof(t_rl_input));
	if (direction == KEY_UP)
		current = backwardsearch(input, &search, current);
	else
		current = forwardsearch(input, &search, current);
	if (!current)
		current = initial;
	ft_rl_updateinput(input, current->blk);
	ft_rl_history_setcurrent(current);
}


static t_list	*forwardsearch(t_rl_input *input, t_rl_input *search, t_list *initial)
{
	(void)input;
	(void)search;
	(void)initial;
	return (NULL);
}

static t_list	*backwardsearch(t_rl_input *input, t_rl_input *search, t_list *initial)
{
	int		rv;
	int		pos[2];
	t_list	*current;

	current = NULL;
	updateprompt(search, "bck-i-search: ");
	ft_rl_term_cur_getpos(&pos[0], &pos[1], 0);
	pos[0] += 1;
	ft_rl_term_cur_setpos(pos[0], 1);
	pos[1] = ft_putstr_fd(search->prompt, 1) + 1;
	rv = ft_rl_history_getpattern(search, pos[0], pos[1]);
	while (rv > 0)
	{
		current = ft_rl_history_match(initial, search->input, KEY_UP);
		if (current)
			ft_rl_history_setcurrent(current);
		displaymatch(input, search, current, pos);
		rv = ft_rl_history_getpattern(search, pos[0], pos[1]);
	}
	if (rv < 1)
		ft_rl_altcmd(input, 1);
	return (current);
}

static void		displaymatch(t_rl_input *input, t_rl_input *search, t_list *current, int *ipos)
{
	if (current)
	{
		ft_rl_updateinput(input, current->blk);
		if (search->promptlen != 14)
			updateprompt(search, "bck-i-search: ");
	}
	else if (search->promptlen == 14 && search->inputlen > 0)
		updateprompt(search, "failing bck-i-search: ");
	ft_rl_term_cur_setpos(ipos[0], 1);
	ft_putstr_fd(search->prompt, 1);
	if (search->input)
		ft_putstr_fd(search->input, 1);
}

static void		updateprompt(t_rl_input *search, char *newprompt)
{
	if (search->prompt)
		ft_popblk((void *)search->prompt);
	search->prompt = ft_push(ft_strdup(newprompt));
	search->promptlen = ft_strlen(search->prompt);
}
