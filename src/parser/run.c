/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:57:40 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/18 14:26:14 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "minish.h"

static int	run_tree(t_node *tree);

int	execute_string(char *s)
{
	t_node		*tree;
	int			validity;
	const int	backup_fds_dont_fucking_touch[2] = {dup(0), dup(1)};

	validity = is_valid(s);
	if (validity != 0)
		return (parse_error(validity));
	// s = parse_heredocs(s);
	tree = make_tree(s);
	validity = validate_tree(tree);
	if (validity != 0)
		return (tree_parse_error(validity, tree));
	run_tree(tree);
	ft_dprintf(2, "%i %i\n", backup_fds_dont_fucking_touch[0], backup_fds_dont_fucking_touch[1]);
	dup2(backup_fds_dont_fucking_touch[0], 0);
	dup2(backup_fds_dont_fucking_touch[1], 1);
	close(backup_fds_dont_fucking_touch[0]);
	close(backup_fds_dont_fucking_touch[1]);
	save_pipeline(NULL, 1);
	return (0);
}

static int	set_exitcode(int exitcode)
{
	msh_setenv("?", ft_itoa(exitcode));
	return (exitcode);
}

static int	run_tree(t_node *tree)
{
	int	exitcode;

	if (tree->left && tree->right)
	{
		exitcode = run_tree(tree->left);
		if (ft_strncmp(tree->content, "||", 2) == 0)
		{
			if (exitcode && exitcode != 130)
				return (run_tree(tree->right));
			else
				return (exitcode);
		}
		else if (ft_strncmp(tree->content, "&&", 2) == 0)
		{
			if (!exitcode && exitcode != 130)
				return (run_tree(tree->right));
			else
				return (exitcode);
		}
		else
			return (-1);
	}
	else
		return (set_exitcode(exec_pipeline(tree->content)));
}
