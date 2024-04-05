/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:57:40 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/05 14:27:09 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "minish.h"

static int	run_tree(t_node *tree);
static void	fix_fds(int backup_fds_dont_fucking_touch[2]);

/*
	executes the whole string
*/
int	execute_string(char *s)
{
	t_node		*tree;
	int			validity;
	const int	backup_fds_dont_fucking_touch[2] = {dup(0), dup(1)};

	validity = is_valid(s);
	if (validity != 0)
	{
		fix_fds((int *)backup_fds_dont_fucking_touch);
		return (parse_error(validity));
	}
	tree = make_tree(s);
	validity = validate_tree(tree);
	if (validity != 0)
	{
		fix_fds((int *)backup_fds_dont_fucking_touch);
		return (tree_parse_error(validity, tree));
	}
	run_tree(tree);
	fix_fds((int *)backup_fds_dont_fucking_touch);
	return (0);
}

/*
	puts the default fds back to a usable state
	and reset the running pipeline
*/
static void	fix_fds(int backup_fds_dont_fucking_touch[2])
{
	dup2(backup_fds_dont_fucking_touch[0], 0);
	dup2(backup_fds_dont_fucking_touch[1], 1);
	close(backup_fds_dont_fucking_touch[0]);
	close(backup_fds_dont_fucking_touch[1]);
	save_pipeline(NULL, 1);
}

/*
	saves exit code after each pipeline
*/
static int	set_exitcode(int exitcode)
{
	msh_setenv("?", ft_push(ft_itoa(exitcode)));
	return (exitcode);
}

/*
	recursivly executes pipelines, stops on Ctrl+C
*/
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
