/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:27:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/26 13:54:44 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_list	*execsearch(t_rl_input **io, t_list *first, char *p, char dir);
static void		displaymatch(t_rl_input **io, t_list *cur, int *ipos, char dir);
static void		initprompt(t_rl_input **io, char *p, int *row, int *col);
static void		updateprompt(t_rl_input *search, char *newprompt);

int	ft_rl_history_search(t_rl_input *input, char direction)
{
	int			pos[2];
	t_list		*current;
	t_rl_input	*inputs[2];
	t_rl_input	search;

	current = *ft_rl_history_getcurrent(0);
	if ((direction == KEY_DOWN && !current->prev)
		|| (direction == KEY_UP && !current->next))
		return (-1);
	ft_rl_term_cur_getpos(&pos[0], &pos[1], 0);
	ft_bzero(&search, sizeof(t_rl_input));
	inputs[0] = input;
	inputs[1] = &search;
	ft_push(current->blk);
	if (direction == KEY_UP)
		current = execsearch(inputs, current, "bck-i-search: ", direction);
	else
		current = execsearch(inputs, current, "fwd-i-search: ", direction);
	ft_rl_updateinput(input, current->blk, NULL);
	ft_rl_term_cur_setpos(pos[0], input->promptlen + input->inputlen + 1);
	ft_rl_history_setcurrent(current);
	ft_rl_redisplay(input);
	return (ft_strrchr(search.input, '\n') != NULL);
}

static t_list	*execsearch(t_rl_input **io, t_list *first, char *p, char dir)
{
	int		rv;
	int		pos[2];
	t_list	*current;

	initprompt(io, p, &pos[0], &pos[1]);
	rv = ft_rl_history_getpattern(io[1], pos[0], pos[1]);
	while (rv > 0 && !ft_strrchr(io[1]->input, '\n'))
	{
		if (!io[1]->inputlen)
			current = first;
		else
		{
			current = ft_rl_history_match(first, io[1]->input, dir);
			if (current)
				ft_rl_history_setcurrent(current);
		}
		displaymatch(io, current, pos, dir);
		rv = ft_rl_history_getpattern(io[1], pos[0], pos[1]);
	}
	if (rv < 0)
		ft_rl_altcmd(io[0], 1);
	ft_popblk(first->blk);
	if (!io[1]->inputlen)
		return (first);
	return (current);
}

static void	displaymatch(t_rl_input **io, t_list *cur, int *ipos, char dir)
{
	if (cur)
	{
		ft_rl_updateinput(io[0], cur->blk,
			ft_rl_history_getmatchrange(cur->blk, io[1]->input));
		if (io[1]->promptlen != 14)
		{
			if (dir == KEY_UP)
				updateprompt(io[1], "bck-i-search: ");
			else
				updateprompt(io[1], "fwd-i-search: ");
		}
	}
	else if (io[1]->promptlen == 14 && io[1]->inputlen > 0)
	{
		if (dir == KEY_UP)
			updateprompt(io[1], "failing bck-i-search: ");
		else
			updateprompt(io[1], "failing fwd-i-search: ");
	}
	ft_rl_term_cur_setpos(ipos[0], 1);
	ft_putstr_fd(io[1]->prompt, 1);
	if (io[1]->input)
		ft_putstr_fd(io[1]->input, 1);
}

static void	initprompt(t_rl_input **io, char *p, int *row, int *col)
{
	updateprompt(io[1], p);
	ft_rl_term_cur_getpos(row, col, 0);
	*row += 1;
	ft_rl_term_cur_setpos(*row, 1);
	*col = ft_putstr_fd(io[1]->prompt, 1) + 1;
}

static void	updateprompt(t_rl_input *search, char *newprompt)
{
	if (search->prompt)
		ft_popblk((void *)search->prompt);
	search->prompt = ft_push(ft_strdup(newprompt));
	search->promptlen = ft_strlen(search->prompt);
}
