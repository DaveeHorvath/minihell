/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:57:40 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/05 16:08:26 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	run_tree(t_node tree)
{
	int	exitcode;

	if (tree.left && tree.right)
	{
		exitcode = run_tree(tree.left);
		if (ft_strncmp(tree.content, "||", 2) == 0)
		{
			if (exitcode)
				return (run_tree(tree.right));
			else
				return (exitcode);
		}
		else if (ft_strncmp(tree.content, "&&", 2) == 0)
		{
			if (!exitcode)
				return (run_tree(tree.right));
			else
				return (exitcode);
		}
	}
	else
		return (exec_pipeline(tree.content));
}

int	execute_string(char *s)
{
	t_node	tree;

	tree = make_tree(s);
	if (!validate_tree(tree))
		return (-1);
	run_tree(tree);
}
