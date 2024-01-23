/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:59:49 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/23 00:26:58 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
typedef struct s_node
{
	struct s_node	*left;
	struct s_node	*right;
	char			*content;
}	t_node;
*/

int	get_sep_index(char *s)
{
	char	quote;
	int		i;
	int		brackets;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
		}
		else if (s[i] == '(')
			brackets++;
		else if (s[i] == ')' && brackets)
			brackets--;
		else if (ft_strcmp(&s[i], "&&", 2)
			|| ft_strcmp(&s[i], "||", 2) && !brackets)
			return (i);
		i++;
	}
	return (-2);
}

t_node	*make_tree(char *s)
{
	t_node	res;
	int		sep_index;

	if (!s)
		return (NULL);
	sep_index = get_sep_index(s);
	if (sep_index == -2)
	{
		res = (t_node){.left = NULL, .right = NULL, .content = s};
		return (&res);
	}
	else if (sep_index != -1)
	{
		res.left = make_tree(ft_substr(s, 0, sep_index - 1));
		res.right = make_tree(ft_substr(s, sep_index + 2, ft_strlen(s)));
		res.content = ft_substr(s, sep_index, 2);
	}
	else
		return (NULL);
}
