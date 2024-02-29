/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:11:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/24 19:53:58 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_readline.c
 */

#include "ft_readline.h"

static size_t	getpromptlen(const char *prompt);
static char		*getline(const char *prompt);

/** @brief man 3 readline
 *
 * If something specified on the man page doesn't work it's not implemented
 * @param *p Prompt string
 * @retval char* Pointer to the line that was read,
 * or NULL if read EOF with no prior input
 */
char	*ft_readline(const char *prompt)
{
	t_rl_termsettings	term;
	static char			init = 0;
	t_list				*history;
	char				*line;

	tcgetattr(0, &term.oldsettings);
	term.newsettings = term.oldsettings;
	term.newsettings.c_lflag &= (~ICANON & ~ECHO);
	tcsetattr(0, TCSANOW, &term.newsettings);
	if (!init)
	{
		ft_rl_history_load();
		init = 1;
	}
	history = *ft_rl_history_gethead();
	if (!history || *history->size <= RL_HISTORY_SIZE)
		ft_lstadd_front(ft_rl_history_gethead(), ft_lstnew(ft_strdup("")));
	else
		ft_rl_history_recycle();
	line = getline(prompt);
	ft_rl_history_commit(line);
	tcsetattr(0, TCSANOW, &term.oldsettings);
	return (line);
}

static size_t	getpromptlen(const char *prompt)
{
	size_t	i;

	i = 0;
	while (*prompt)
	{
		if (*prompt == '\e')
		{
			while (*prompt && *prompt != 'm')
				prompt++;
			prompt++;
		}
		if (*prompt == '\e')
			continue ;
		if (!*prompt)
			break ;
		prompt++;
		i++;
	}
	return (i);
}

static char	*getline(const char *prompt)
{
	t_rl_input	input;
	int			rv;

	input.i = 0;
	input.input = ft_push(ft_strdup(""));
	input.prompt = prompt;
	input.inputlen = 0;
	input.promptlen = getpromptlen(prompt);
	ft_rl_term_cur_updatepos(input.promptlen);
	ft_putstr_fd(prompt, 1);
	rv = ft_rl_getinput(&input);
	while (rv > 0)
		rv = ft_rl_getinput(&input);
	if (rv < 0)
	{
		ft_popblk(input.input);
		return (NULL);
	}
	return (input.input);
}
