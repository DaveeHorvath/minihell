/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:59:49 by dhorvath          #+#    #+#             */
/*   Updated: 2024/04/16 13:42:11 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "builtins.h"

/*
	compares string s to the builtins
*/
int	is_builtin(char *s, int isexpanded)
{
	char	**args;

	if (isexpanded)
		args = &s;
	else
		args = get_args(get_tokens(ft_push(ft_strtrim(s, " "))));
	if (ft_strequals(args[0], "cd") || ft_strequals(args[0], "echo")
		|| ft_strequals(args[0], "unset") || ft_strequals(args[0], "export")
		|| ft_strequals(args[0], "exit") || ft_strequals(args[0], "pwd")
		|| ft_strequals(args[0], "env"))
		return (1);
	else
		return (0);
}

/*
	executes builtin, if actual exit is 1 its not run in a fork
	closes the filedescriptors after, should only be run if isbuiltin is true
*/
int	exec_builtin(char *s, int outfd, int actual_exit)
{
	char			**args;
	const t_tokens	*tokens = get_tokens(ft_push(ft_strtrim(s, " ")));
	const int		fds[2] = {0, outfd};
	int				exitcode;

	expand_wildcards((t_tokens **)&tokens);
	args = get_args((t_tokens *)tokens);
	if (get_fds((t_tokens *)tokens, (int *)fds) == 0)
		return (1);
	if (ft_strequals(args[0], "cd"))
		exitcode = msh_cd(args[1]);
	else if (ft_strequals(args[0], "echo"))
		exitcode = msh_echo(&args[1], fds[1]);
	else if (ft_strequals(args[0], "unset"))
		exitcode = msh_unset(&args[1]);
	else if (ft_strequals(args[0], "export"))
		exitcode = msh_export(&args[1]);
	else if (ft_strequals(args[0], "exit"))
		exitcode = msh_exit(&args[1], actual_exit);
	else if (ft_strequals(args[0], "pwd"))
		exitcode = msh_pwd(fds[1]);
	else
		exitcode = msh_env(fds[1]);
	smart_closer((int *)fds);
	return (exitcode);
}
