/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_increment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:02:50 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/19 20:14:01 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void	compare(t_list *start, t_list *completions, char *common);

void	ft_rl_complete_increment(t_list *completions, char *word)
{
	char	*common;
	t_list	*start;
	size_t	maxlen;

	maxlen = ft_rl_complete_getlongest(completions);
	common = ft_calloc(maxlen + 1, sizeof(char));
	if (!common)
		return ;
	start = completions;
	compare(start, completions, common);
	if (!*common || ft_strequals(word, common))
		return ;
	completions = start;
	ft_popblk(completions->blk);
	completions->blk = ft_push(common);
	ft_lstpopall(completions->next);
	completions->next = NULL;
}

static void	compare(t_list *start, t_list *completions, char *common)
{
	char	current;
	size_t	i;

	i = 0;
	current = (*(char *)completions->blk + i);
	while (current)
	{
		completions = completions->next;
		if (!completions)
		{
			common[i++] = current;
			completions = start;
			current = *((char *)completions->blk + i);
			continue ;
		}
		if (*((char *)completions->blk + i) == current)
			continue ;
		break ;
	}
}
