/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:56:37 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/16 13:40:15 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

char	*get_filename(char *s, int start)
{
	int	i;

	i = start;
	while (s[i] == ' ')
		i++;
	return (ft_push(ft_strdup(&s[i])));
}

void	smart_closer(int *fds)
{
	if (fds[0] != 0)
		close(fds[0]);
	if (fds[1] != 1)
		close(fds[1]);
}

/*
	changes quote if applicable
	returns 1 if change happened otherwise 0
*/
int	update_quote(char c, enum e_quotes *quote)
{
	if (c == '\'' && *quote == none)
	{
		*quote = singlequote;
		return (1);
	}
	else if (c == '\"' && *quote == none)
	{
		*quote = doublequote;
		return (1);
	}
	else if (c == '\'' && *quote == singlequote)
	{
		*quote = none;
		return (1);
	}
	else if (c == '\"' && *quote == doublequote)
	{
		*quote = none;
		return (1);
	}
	return (0);
}

t_tokens	*addfront(t_tokens *new_tokens, t_tokens **tokenlist,
				t_tokens *next)
{
	if (*tokenlist)
	{
		(*tokenlist)->next = new_tokens;
		while (new_tokens && new_tokens->next)
			new_tokens = new_tokens->next;
		new_tokens->next = next;
		return (new_tokens);
	}
	else
	{
		*tokenlist = new_tokens;
		while (new_tokens && new_tokens->next)
			new_tokens = new_tokens->next;
		new_tokens->next = next;
		return (new_tokens);
	}
}
