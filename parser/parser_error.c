/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:34:37 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/22 23:41:23 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*clean(void)
{
	return (0);
}

void	child_error(void)
{
	clean();
	printf("something went stupid\n");
	exit(-1);
}

void	command_not_found(void)
{
	clean();
	printf("no such command stupid\n");
	exit(-1);
}
