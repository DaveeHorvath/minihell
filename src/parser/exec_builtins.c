/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:59:49 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/02 12:22:34 by dhorvath         ###   ########.fr       */
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

int	exec_builtin(char *s, int outfd, int actual_exit)
{
	char		**args;
	t_tokens	*tokens;
	int			fds[2];
	int			exitcode;

	fds[0] = 0;
	fds[1] = outfd;
	tokens = get_tokens(ft_strtrim(s, " "));
	args = get_args(tokens);
	get_fds(tokens, fds);
	if (ft_strequals(args[0], "cd"))
		exitcode = msh_cd(args[1]);
	if (ft_strequals(args[0], "echo"))
		exitcode = msh_echo(&args[1], fds[1]);
	if (ft_strequals(args[0], "unset"))
		exitcode = msh_unset(&args[1]);
	if (ft_strequals(args[0], "export"))
		exitcode = msh_export(&args[1]);
	if (ft_strequals(args[0], "exit"))
		exitcode = msh_exit(&args[1], actual_exit);
	if (ft_strequals(args[0], "pwd"))
		exitcode = msh_pwd(fds[1]);
	else
		exitcode = msh_env(fds[1]);
	if (fds[0] != 0)
		close(fds[0]);
	if (fds[1] != 1)
		close(fds[1]);
	return (exitcode);
}
