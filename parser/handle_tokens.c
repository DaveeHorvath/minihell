/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:34:48 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/06 14:36:11 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int	handle_quotes(char *s)
{
	int		i;
	char	c;

	c = *s;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	handle_redirect(char *s, t_list **tokens, int start)
{
	int	i;

	i = start;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i] && s[i] != ' ' && s[i] != '<' && s[i] != '>')
		i++;
	append(tokens, ft_substr(s, 0, i));
	return (i);
}

int	handle_sppace(char *s, int i, int *old_i, t_list **tokens)
{
	int	counter;

	append(tokens, ft_substr(s, 0, i));
	counter = 0;
	while (s[i + counter] && s[i + counter] == ' ')
		counter++;
	*old_i = i + counter;
	return (counter);
}
