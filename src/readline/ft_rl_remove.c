/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:52:04 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/14 15:50:58 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"
#include "ft_rl_keys_ascii.h"

void	ft_rl_rmchar(t_rl_input *input)
{
	t_rl_word	*curword;
	char		*newword;

	if (!input->current || (!input->current->next
			&& input->current->i == input->current->len))
		return ;
	curword = input->current;
	if (curword->len == 1)
	{
		ft_rl_rmword(input, curword, KEY_DEL);
		return ;
	}
	newword = ft_calloc(ft_getblksize(curword->word), sizeof(*newword));
	if (!ft_push(newword))
		return ;
	ft_popblk(curword->word);
	ft_strlcpy(newword, curword->word, curword->i + 1);
	ft_strlcpy(newword + curword->i, curword->word + curword->i + 1,
		curword->len-- - curword->i + 2);
	curword->word = newword;
}

void	ft_rl_rmchar_bck(t_rl_input *input)
{
	t_rl_word	*curword;
	char		*newword;

	if (!input->current)
		return ;
	curword = input->current;
	if (curword->i == 0)
		curword = curword->prev;
	if (!curword)
		return ;
	if (curword->len == 1)
	{
		ft_rl_rmword(input, curword, KEY_BACKSPACE);
		return ;
	}
	newword = ft_calloc(ft_getblksize(curword->word), sizeof(*newword));
	if (!ft_push(newword))
		return ;
	ft_popblk(curword->word);
	ft_strlcpy(newword, curword->word, curword->i);
	ft_strlcpy(newword + curword->i - 1, curword->word + curword->i,
		curword->len-- - curword->i + 1);
	curword->word = newword;
	curword->i--;
}
