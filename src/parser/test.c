/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:16:22 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/19 21:44:54 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>
#include <fcntl.h>

// int	main(int argc, char **argv, char **env)
// {
// 	char *arg[] = {"wc", "-l", NULL};
// 	int	fd_out = open("Makefile", O_RDONLY);
// 	int status;
// 	(void) argc; (void) argv;
// 	execute_string("echo 2 | cat <a >c echo 1 | ls | wc -l | echo $PATH | clear)");
// 	t_cmd cmd = (t_cmd){.argv=arg, .env=env, .fd={fd_out, 1}};
// 	do_cmd(&cmd);
// 	waitpid(cmd.pid, &status, 1);
// 	close(fd_out);
// }


int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	execute_string("(echo 1 && echo 2) && echo 3");
	execute_string("(ls) && echo 2");
}
