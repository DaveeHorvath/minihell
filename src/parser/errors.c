/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:50:18 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/04 22:59:00 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

void	cmd_not_found(t_cmd *cmd)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd->argv[0], 2);
	ft_putstr_fd("\n", 2);
	exit(127);
}

void	child_error(void)
{
	ft_putstr_fd("something went to shit, the child is crying again\n", 1);
	exit(-1);
}

int	handle_file_error(int start, char *s)
{
	printf("file %s doenst exist\n",
		expand_token(get_filename(s, start), NULL, none));
	return (1);
}

int	parse_error(int error)
{
	if (error == WRONG_PARENTHESIES)
		ft_printf("Wrong parenthesies\n");
	else if (error == UNMATCHED_S_QUOTE)
		ft_printf("Unmatched single quote\n");
	else if (error == UNMATCHED_D_QUOTE)
		ft_printf("Unmatched double quote\n");
	else if (error == UNMATCHED_PARENTHESIES)
		ft_printf("Unmatched parenthesies\n");
	else if (error == SYNTAX_ERROR)
		ft_printf("Syntax error\n");
	else
		ft_printf("Unrecognised error\n");
	return (-1);
}

// toadd popping tree nodes and contents
int	tree_parse_error(int error, t_node *tree)
{
	(void) tree;
	if (error == MALLOC_FAIL)
		ft_printf("Malloc failed while creating tree\n");
	else if (error == PARENTHESIES_IN_NODE)
		ft_printf("Parenthesies inside pipeline\n");
	return (-1);
}
