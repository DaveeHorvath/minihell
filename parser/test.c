/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:16:22 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/16 20:18:09 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

int	main(void)
{
	get_command(" >a teasdst >>     test \'<a\' >b   <<   \"ad\"  testststatas  testasd ");
	//printf("%s\n", cmd->argv[0]);
}
