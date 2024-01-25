/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:59:49 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/24 15:31:53 by dhorvath         ###   ########.fr       */
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

char	*strip_brackets(char *s)
{
	int		i;
	char	quote;
	int		end;

	if (!s)
		return (NULL);
	i = 0;
	end = ft_strlen(s) - 1;
	if (get_sep_index(s) == -1)
	{
		while (s[i] && isspace(s[i]) && s[i] != '(')
			i++;
		if (!s[i] || s[i] != '(')
			return (s);
		while (end >= 0 && isspace(s[end]) && s[end] != ')')
			end--;
		return (strip_brackets(ft_substr(s, i, end - i)));
	}
	else
		return (s);
}

t_node	*make_tree(char *s)
{
	t_node	res;
	int		sep_index;

	s = strip_brackets(s);
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
		return (&res);
	}
	else
		return (NULL);
}
