/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_completionutils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:09:33 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/28 10:53:18 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void	calculateoutput(t_list *completions, size_t *maxwidth, size_t *cpl);
static char	*completionstring(t_list *cmp, char *curr, size_t maxw, size_t cpl);
static char	*padstring(char *s, char *current, size_t width);

size_t	ft_rl_complete_getlongest(t_list *completions)
{
	size_t	maxlen;
	size_t	len;

	maxlen = 0;
	while (completions)
	{
		len = ft_strlen(completions->blk);
		if (len > maxlen)
			maxlen = len;
		completions = completions->next;
	}
	return (maxlen);
}

void	printcompletions(t_list *completions, char *current)
{
	t_rl_termstate	*state;
	size_t			maxwidth;
	size_t			cpl;
	int				row;
	int				col;

	state = ft_rl_term_getstate();
	ft_rl_term_cur_getpos(&row, &col, 0);
	calculateoutput(completions, &maxwidth, &cpl);
	ft_printf("\n%s",
		ft_strtrim(completionstring(completions, current, maxwidth, cpl), " "));
	while (row + (*completions->size / cpl) >= (size_t)state->t_rows)
	{
		state->i_row--;
		row--;
	}
	ft_rl_term_cur_setpos(row, col);
}

static void	calculateoutput(t_list *completions, size_t *maxwidth, size_t *cpl)
{
	t_rl_termstate	*state;
	size_t			curwidth;

	*maxwidth = 0;
	while (completions)
	{
		curwidth = ft_strlen(completions->blk);
		if (curwidth > *maxwidth)
			*maxwidth = curwidth;
		completions = completions->next;
	}
	(*maxwidth)++;
	state = ft_rl_term_getstate();
	*cpl = state->t_cols / *maxwidth;
	if (!*cpl)
		(*cpl)++;
}

static char	*completionstring(t_list *cmp, char *curr, size_t maxw, size_t cpl)
{
	size_t	i;
	char	*out;
	char	*newstring;

	out = NULL;
	i = 0;
	while (cmp)
	{
		ft_push(out);
		newstring = padstring(cmp->blk, curr, maxw);
		if (out)
			ft_popblk(out);
		if (i != cpl)
		{
			out = ft_strsjoin(out, newstring, ' ');
			i++;
		}
		else
		{
			out = ft_strsjoin(out, newstring, '\n');
			i = 1;
		}
		cmp = cmp->next;
	}
	return (out);
}

static char	*padstring(char *s, char *current, size_t width)
{
	size_t	i;
	char	dir;
	char	*tmp;
	char	*out;

	if (ft_strrchr(s, '/'))
	{
		tmp = s;
		dir = ft_rl_isdir(s);
		while (ft_strchr(s, '/') != ft_strrchr(s, '/'))
			s = ft_strchr(s, '/') + 1;
		if (!dir)
			s = ft_strchr(s, '/') + 1;
	}
	out = ft_calloc(width + 1, sizeof(char));
	i = ft_strlen(s);
	ft_strlcpy(out, s, i + 1);
	while (i < width)
		out[i++] = ' ';
	if (tmp == current)
	{
		out = ft_strjoin(SGR_FG4, out);
		out = ft_strjoin(out, SGR_FGR);
	}
	return (out);
}
