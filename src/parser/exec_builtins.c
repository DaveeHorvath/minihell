/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:59:49 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/26 18:03:57 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "builtins.h"

int	is_builtin(char *s)
{
	char	**args;

	args = get_args(get_tokens(ft_strtrim(s, " ")));
	if (ft_strequals(args[0], "cd") || ft_strequals(args[0], "echo")
		|| ft_strequals(args[0], "unset") || ft_strequals(args[0], "export")
		|| ft_strequals(args[0], "exit"))
		return (1);
	else
		return (0);
}

int	exec_builtin(char *s, int fd[2])
{
	char		**args;
	t_tokens	*tokens;
	int			fds[2];
	int			exitcode;

	tokens = get_tokens(ft_strtrim(s, " "));
	args = get_args(tokens);
	get_fds(tokens, fds);
	if (ft_strequals(args[0], "cd"))
		exitcode = msh_cd(args[1]);
	if (ft_strequals(args[0], "echo"))
		exitcode = msh_echo(args[1], fd[1]);
	if (ft_strequals(args[0], "unset"))
		exitcode = msh_unset(args[1]);
	if (ft_strequals(args[0], "export"))
		exitcode = msh_export(args[1]);
	if (ft_strequals(args[0], "exit"))
		exitcode = msh_exit(69420);
	if (ft_strequals(args[0], "pwd"))
		exitcode = msh_pwd();
	else
		exitcode = msh_env(/*out_fd*/);
	if (fd[0] != 0)
		close(fd[0]);
	if (fd[1] != 1)
		close(fd[1]);
	return (exitcode);
}
