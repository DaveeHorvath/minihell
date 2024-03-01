/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:24:18 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/27 14:57:16 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int	is_valid(char *s)
{
	int	i;
	int	parenthesies;

	parenthesies = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '(')
		{
			parenthesies++;
			i++;
		}
		else if (s[i] == ')')
		{
			if (parenthesies == 0)
				return (WRONG_PARENTHESIES);
			parenthesies--;
			while (s[i] && (ft_strncmp(&s[i], "&&", 2) == 0
					|| ft_strncmp(&s[i], "||", 2) == 0))
			{
				if (s[i] != ' ' || s[i] != '\t')
					return (SYNTAX_ERROR);
				i++;
			}
		}
		else if (s[i] == '\'')
		{
			while (s[i] && s[i] != '\'')
				i++;
			if (s[i] == '\0')
				return (UNMATCHED_S_QUOTE);
		}
		else if (s[i] == '\"')
		{
			while (s[i] && s[i] != '\"')
				i++;
			if (s[i] == '\0')
				return (UNMATCHED_D_QUOTE);
		}
		else
			i++;
	}
	if (parenthesies == 0)
		return (0);
	else
		return (UNMATCHED_PARENTHESIES);
}

int	validate_pipeline(char *s)
{
	int		i;
	int		j;
	char	**commands;

	if (!s)
		return (1);
	commands = ft_pusharr(ft_split(s, '|'));
	i = 0;
	while (commands[i])
	{
		j = 0;
		while (commands[i][j] && commands[i][j] == ' ')
			j++;
		if (!commands[i][j])
			return (PIPELINE_ISSUE);
	}
	return (0);
}

int	validate_tree(t_node *tree)
{
	int		error;
	int		i;
	char	c;

	if (tree->left || tree->right)
	{
		if (!tree->content || !(tree->left && tree->right))
			return (MALLOC_FAIL);
		error = validate_tree(tree->left);
		if (error == 0)
			return (validate_tree(tree->right));
		else
			return (error);
	}
	else
	{
		if (!tree->content || ft_strequals(tree->content, "&&")
			|| ft_strequals(tree->content, "||"))
			return (MALLOC_FAIL);
		i = 0;
		while (tree->content[i])
		{
			if (tree->content[i] == '\"' || tree->content[i] == '\'')
			{
				c = tree->content[i];
				while (tree->content[i] && tree->content[i] != c)
					i++;
			}
			else if (tree->content[i] == '(' || tree->content[i] == ')')
				return (PARENTHESIES_IN_NODE);
			else
				i++;
		}
		if (validate_pipeline(tree->content) != 0)
			return (PIPELINE_ISSUE);
		return (0);
	}
}
