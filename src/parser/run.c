/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:57:40 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/26 14:18:57 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static int	run_tree(t_node *tree);

int	execute_string(char *s)
{
	t_node	*tree;

	tree = make_tree(s);
	run_tree(tree);
	return (0);
}

static int	run_tree(t_node *tree)
{
	int	exitcode;

	if (tree->left && tree->right)
	{
		exitcode = run_tree(tree->left);
		if (ft_strncmp(tree->content, "||", 2) == 0)
		{
			if (exitcode)
				return (run_tree(tree->right));
			else
				return (exitcode);
		}
		else if (ft_strncmp(tree->content, "&&", 2) == 0)
		{
			if (!exitcode)
				return (run_tree(tree->right));
			else
				return (exitcode);
		}
		else
			return (-1);
	}
	else
		return (exec_pipeline(tree->content));
}
