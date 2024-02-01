/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:57:40 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/26 10:59:57 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	execute_string(char *s)
{
	t_node	*tree;

	s = parse_string(s);
	tree = make_tree(s);
	if (!tree)
		return (-1);
	run_tree(tree);
}