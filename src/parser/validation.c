/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:24:18 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/17 20:55:47 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static int	after_parenthesies_check(char *s, int *i, int *parenthesies)
{
	(*i)++;
	if ((*parenthesies)-- == 0)
		return (WRONG_PARENTH);
	while (ft_strncmp(&s[*i], "&&", 2) != 0 && ft_strncmp(&s[*i], "||", 2) != 0)
	{
		if (s[*i] && s[*i] != ' ' && s[*i] != '\t')
			return (SYNTAX_ERROR);
		if (!s[*i])
			break ;
		(*i)++;
	}
	return (0);
}

int	is_valid(char *s)
{
	int		i;
	int		p;
	char	c;

	p = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '(')
			p++;
		else if (s[i] == ')')
		{
			if (after_parenthesies_check(s, &i, &p) != 0)
				return ((p == -1) * WRONG_PARENTH + (p != -1) * SYNTAX_ERROR);
		}
		else if (s[i] == '\'' || s[i] == '\"')
		{
			c = s[i++];
			while (s[i] && s[i] != c)
				i++;
			if (s[i] == '\0')
				return (U_S_QUOTE * (c == '\'') + U_D_QUOTE * (c == '\"'));
		}
	}
	return (UNMATCHED_PARENTHESIES * (p != 0));
}

int	validate_pipeline(char *s)
{
	int		i;
	int		j;
	char	**commands;

	if (!s)
		return (1);
	commands = ft_quoted_split(s, '|');
	i = 0;
	while (commands[i])
	{
		j = 0;
		while (commands[i][j] == ' ')
			j++;
		if (!commands[i][j] || commands[i][j] == '|')
			return (PIPELINE_ISSUE);
		i++;
	}
	return (0);
}

static int	validate_children(t_node *tree)
{
	int		error;

	if (!tree->content || !(tree->left && tree->right))
		return (MALLOC_FAIL);
	error = validate_tree(tree->left);
	if (error == 0)
		return (validate_tree(tree->right));
	else
		return (error);
}

int	validate_tree(t_node *tree)
{
	int		i;
	char	c;

	if (tree->left || tree->right)
		return (validate_children(tree));
	else
	{
		if (!tree->content || ft_strnstr(tree->content, "&&",
				ft_strlen(tree->content))
			|| ft_strnstr(tree->content, "||", ft_strlen(tree->content)))
			return (MALLOC_FAIL);
		i = 0;
		while (tree->content[i])
		{
			if (tree->content[i] == '\"' || tree->content[i] == '\'')
			{
				c = tree->content[i++];
				while (tree->content[i] != c)
					i++;
			}
			i++;
		}
		return (PIPELINE_ISSUE * (validate_pipeline(tree->content) != 0));
	}
}
