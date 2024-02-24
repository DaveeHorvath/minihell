/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_completionutils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:09:33 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/24 21:25:43 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void	calculateoutput(t_list *completions, size_t *maxwidth, size_t *cpl);
static char	*completionstring(t_list *completions, char *current, size_t maxwidth, size_t cpl);
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
	ft_printf("\n%s", completionstring(completions, current, maxwidth, cpl));
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

static char	*completionstring(t_list *completions, char *current, size_t maxwidth, size_t cpl)
{
	size_t	i;
	char	*out;
	char	*newstring;

	out = NULL;
	i = 1;
	while (completions)
	{
		ft_push(out);
		newstring = padstring(completions->blk, current, maxwidth);
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
		completions = completions->next;
	}
	return (out);
}

static char	*padstring(char *s, char *current, size_t width)
{
	size_t	i;
	char	*out;

	out = ft_calloc(width + 1, sizeof(char));
	i = ft_strlen(s);
	ft_strlcpy(out, s, i + 1);
	while (i < width)
		out[i++] = ' ';
	if (s == current)
	{
		out = ft_strjoin(SGR_FG4, out);
		out = ft_strjoin(out, SGR_FGR);
	}
	return (out);
}
