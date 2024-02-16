/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:34:48 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/16 20:20:10 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../libft/libft.h"

static void	append(t_list **list, char *s)
{
	t_list	*current;
	t_list	*new;

	current = *list;
	new = ft_push(ft_alloc(sizeof(t_list)));
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

int	handle_quotes(char *s, int i)
{
	char	c;
	int		count;

	count = 0;
	c = s[i];
	while (s[i + count] && s[i + count] != c)
		count++;
	return (count);
}

int	handle_redirect(char *s, int i, t_list **tokens, int start)
{
	int	j;

	j = i + start;
	while (s[j] && s[j] == ' ')
		j++;
	while (s[j] && s[j] != ' ' && s[j] != '<' && s[j] != '>')
		j++;
	append(tokens, ft_push(ft_substr(s, i, j - i)));
	return (j - i);
}

/* tested mostly */
int	handle_space(char *s, int i, int *old_i, t_list **tokens)
{
	int	counter;

	// printf("-%s-  oldi: %i i: %i\n", ft_substr(s, *old_i, i - *old_i), *old_i, i);
	append(tokens, ft_push(ft_substr(s, *old_i, i - *old_i)));
	counter = 0;
	while (s[i + counter] == ' ')
		counter++;
	*old_i = i + counter;
	return (counter);
}
