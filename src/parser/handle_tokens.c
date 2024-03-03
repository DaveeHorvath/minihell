/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:34:48 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/03 17:16:24 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static void	append(t_tokens **list, char *s);

int	handle_quotes(char *s, int i)
{
	char	c;
	int		count;

	count = 1;
	c = s[i];
	while (s[i + count] && s[i + count] != c)
		count++;
	return (count);
}

int	handle_redirect(char *s, int i, t_tokens **tokens, int start)
{
	int				j;
	enum e_quotes	quote;

	quote = none;
	j = i + start;
	while (s[j] && s[j] == ' ')
		j++;
	while (s[j] && !((s[j] == ' ' && quote == none)
			|| (s[j] == '<' && quote == none)
			|| (s[j] == '>' && quote == none)))
	{
		update_quote(s[j], &quote);
		j++;
	}
	append(tokens, ft_push(ft_substr(s, i, j - i)));
	while (s[j] == ' ')
		j++;
	return (j - i);
}

int	handle_space(char *s, int i, int *old_i, t_tokens **tokens)
{
	int	counter;

	append(tokens, ft_push(ft_substr(s, *old_i, i - *old_i)));
	counter = 0;
	while (s[i + counter] == ' ')
		counter++;
	*old_i = i + counter;
	return (counter);
}

static void	append(t_tokens **list, char *s)
{
	t_tokens	*current;
	t_tokens	*new;

	current = *list;
	new = ft_push(ft_alloc(sizeof(t_tokens)));
	new->content = s;
	new->next = NULL;
	if (!current)
	{
		*list = new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
}
