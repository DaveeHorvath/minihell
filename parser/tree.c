/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:05:19 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/05 21:11:55 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static char	*trim_parenthesies(char *s)
{
	int	start;
	int	end;

	start = ft_strchr(s, '(') - s;
	end = ft_strrchr(s, ')') - s;
	return (ft_substr(s, start, end - start));
}

static int	need_parenthesies_remove(char *s)
{
	int		i;
	int		depth;
	char	until;

	i = 0;
	depth = 0;
	while (s && s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			until = s[i];
			while (s[i] && s[i] != until)
				i++;
		}
		else if (s[i] == '(')
			depth += 1;
		else if (s[i] == ')')
			depth -= 1;
		else if (depth == 1 && (ft_strncmp(&s[i], "&&", 2) == 0
				|| ft_strncmp(&s[i], "||", 2) == 0))
			return (-2);
		i++;
	}
	return (-1);
}

static int	get_separator_index(char *s)
{
	int		i;
	int		depth;
	char	until;

	i = 0;
	depth = 0;
	while (s && s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			until = s[i];
			while (s[i] && s[i] != until)
				i++;
		}
		else if (s[i] == '(')
			depth += 1;
		else if (s[i] == ')')
			depth -= 1;
		else if (depth == 0 && (ft_strncmp(&s[i], "&&", 2) == 0
				|| ft_strncmp(&s[i], "||", 2) == 0))
			return (i);
		i++;
	}
	return (need_parenthesies_remove(s));
}

t_node	make_tree(char *s)
{
	t_node	out;
	int		separator_index;

	separator_index = get_separator_index(s);
	if (separator_index == -2)
		return (make_tree(trim_parenthesies(s)));
	else if (separator_index == -1)
		return ((t_node){.left = NULL, .right = NULL, .content = s});
	else
	{
		out.content = ft_push(ft_substr(s, separator_index, 2));
		if (!out.content)
		{
			out.left = NULL;
			out.right = NULL;
			return (out);
		}
		out.left = make_tree(ft_push(ft_substr(s, 0, separator_index)));
		out.right = make_tree(ft_push(ft_substr(s, separator_index + 2,
						ft_strlen(s))));
		return (out);
	}
}
