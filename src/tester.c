/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:08:29 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/15 15:39:02 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "minish.h"

void runtest(char *s);

int main(int argc, char **argv)
{
	extern char	**environ;
	int fd;

	msh_cpyenv(environ);
	msh_setenv("?", "0");
	if (argc == 1)
		fd = open(0, O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_dprintf(2, "error opening file\n");
	else
	{
		for (char *s = ft_push(get_next_line(fd)); s; s = ft_push(get_next_line(fd)))
			runtest(s);
	}
}

void runtest(char *s)
{
	ft_dprintf(2, "running: %s\n", s);
	ft_dprintf(2, "minihell:\n");
	execute_string(s);
	// bash
	ft_dprintf(2, "bash:\n");
	system(s);
}
