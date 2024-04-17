/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:49:34 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/17 18:12:01 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include "parser.h"
#include <unistd.h>

static void			updateprompt(char *format, char **prompt);

int	main(int argc, char **argv)
{
	t_msh_opts	opts;
	extern char	**environ;
	char		*prompt;
	char		*input;

	msh_cpyenv(environ);
	opts = msh_parseopts(argc, argv);
	if (!opts.norc)
		msh_parseconfig(opts.cfg_fname);
	if (!msh_getenv("PROMPT"))
		msh_setenv("PROMPT", DEFAULTPROMPT);
	prompt = NULL;
	signal(2, keyboardinterupt);
	signal(3, keyboardquit);
	msh_setenv("?", "0");
	updateprompt(msh_getenv("PROMPT"), &prompt);
	input = ft_push(ft_readline(prompt, ON));
	while (input)
	{
		execute_string(input);
		ft_popblk(input);
		updateprompt(msh_getenv("PROMPT"), &prompt);
		input = ft_push(ft_readline(prompt, ON));
	}
	return (msh_return(0));
}

static void	updateprompt(char *format, char **prompt)
{
	ft_popblk(*prompt);
	*prompt = ft_push(msh_prompt(format));
	heredoc_stopper(NULL, 1);
}
