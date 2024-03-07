/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:49:34 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/02 13:03:18 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

static void	updateprompt(char *format, char **prompt);

int	main(void)
{
	extern char	**environ;
	char		*prompt;
	char		*input;

	msh_cpyenv(environ);
	parseconfig();
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

static void	updateprompt(char *format, char **prompt)
{
	static char	*oldformat = NULL;

	if (!oldformat)
	{
		oldformat = ft_push(ft_strdup(format));
		*prompt = ft_push(msh_prompt(format));
		return ;
	}
	if (ft_strequals(format, oldformat))
		return ;
	ft_popblk(*prompt);
	ft_popblk(oldformat);
	oldformat = ft_push(ft_strdup(format));
	*prompt = ft_push(msh_prompt(format));
}
