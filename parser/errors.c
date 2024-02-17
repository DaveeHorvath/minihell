/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:50:18 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/17 17:15:16 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "parser.h"
#include <string.h>

void	cmd_not_found(void)
{
	ft_putstr_fd("command not found: ", 1);
	exit(127);
}

void	child_error(void)
{
	ft_putstr_fd("something went to shit, the child is crying again\n", 1);
	exit(-1);
}
