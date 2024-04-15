/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:50:18 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/14 10:55:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

void	cmd_not_found(t_cmd *cmd)
{
	ft_dprintf(2, "minishell: command not found: %s\n", cmd->argv[0]);
	exit(127);
}

void	child_error(int error)
{
	if (error == FORKFAIL)
		ft_dprintf(2, "minishell: Failed to fork\n");
	else if (error == DUP2_ERROR)
		ft_dprintf(2, "minishell: Failed to dup2 filedescriptors\n");
	else if (error == EXECVE_FAIL)
		ft_dprintf(2, "minishell: Failed to execve\n");
	else
		ft_dprintf(2, "something went to shit, the child is crying again\n");
	exit(-1);
}

int	handle_file_error(int start, char *s)
{
	ft_dprintf(2, "minishell: File %s doenst exist\n",
		expand_token(get_filename(s, start), NULL, none));
	return (1);
}

int	parse_error(int error)
{
	if (error == WRONG_PARENTH)
		ft_dprintf(2, "minishell: Closing parenthesies before opening them\n");
	else if (error == U_S_QUOTE)
		ft_dprintf(2, "minishell: Unmatched single quote\n");
	else if (error == U_D_QUOTE)
		ft_dprintf(2, "minishell: Unmatched double quote\n");
	else if (error == UNMATCHED_PARENTHESIES)
		ft_dprintf(2, "minishell: Unmatched parenthesies\n");
	else if (error == SYNTAX_ERROR)
		ft_dprintf(2, "minishell: Syntax error\n");
	else
		ft_dprintf(2, "minishell: Unrecognised error\n");
	return (-1);
}

// toadd popping tree nodes and contents
int	tree_parse_error(int error, t_node *tree)
{
	(void) tree;
	if (error == MALLOC_FAIL)
		ft_dprintf(2, "minishell: Malloc failed to allocate memory\n");
	else if (error == PARENTHESIES_IN_NODE)
		ft_dprintf(2, "minishell: Parenthesies inside pipeline\n");
	else if (error == PIPELINE_ISSUE)
		ft_dprintf(2, "minishell: Issue in pipeline\n");
	return (-1);
}
