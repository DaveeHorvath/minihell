/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:50:18 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/20 16:08:35 by dhorvath         ###   ########.fr       */
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
