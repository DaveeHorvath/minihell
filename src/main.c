/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:49:34 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/07 14:25:40 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

static t_msh_opts	parseopts(size_t argc, char **argv);
static void			updateprompt(char *format, char **prompt);

int	main(int argc, char **argv)
{
	extern char	**environ;
	t_msh_opts	options;
	char		*prompt;
	char		*input;

	msh_cpyenv(environ);
	options = parseopts(argc, argv);
	parseconfig(options.cfg_fname);
	prompt = NULL;
	signal(2, keyboardinterupt);
	msh_setenv("?", "0");
	updateprompt(msh_getenv("PROMPT"), &prompt);
	input = ft_push(ft_readline(prompt));
	while (input)
	{
		execute_string(input);
		ft_popblk(input);
		updateprompt(msh_getenv("PROMPT"), &prompt);
		input = ft_push(ft_readline(prompt));
	}
	return (ft_return(0));
}

static t_msh_opts	parseopts(size_t argc, char **argv)
{
	t_msh_opts	options;
	size_t		i;

	ft_bzero(&options, sizeof(t_msh_opts));
	i = 1;
	while (i < argc)
	{
		if (ft_strequals(argv[i], "--rcfile")
			|| ft_strequals(argv[i], "--init-file"))
		{
			if (++i == argc)
			{
				ft_dprintf(2, "msh: %s: option requires an argument\n",
					ft_strtrim(argv[i - 1], "-"));
				ft_exit(E_ARGS);
			}
			options.cfg_fname = ft_push(ft_strdup(argv[i]));
		}
		i++;
	}
	return (options);
}

static void	updateprompt(char *format, char **prompt)
{
	ft_popblk(*prompt);
	*prompt = ft_push(msh_prompt(format));
}
