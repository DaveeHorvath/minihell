/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:11:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/11 13:19:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_readline.c
 */

#include "ft_readline.h"

static char	*getline(const char *p);

/** @brief man 3 readline
 *
 * If something specified on the man page doesn't work it's not implemented
 * @param *p Prompt string
 * @retval char* Pointer to the line that was read,
 * or NULL if read EOF with no prior input
 */
char	*ft_readline(const char *p)
{
	struct termios	oldsettings;
	struct termios	newsettings;
	static char		init = 0;
	t_list			*history;
	char			*line;

	tcgetattr(0, &oldsettings);
	newsettings = oldsettings;
	newsettings.c_lflag &= (~ICANON & ~ECHO);
	tcsetattr(0, TCSANOW, &newsettings);
	if (!init)
	{
		ft_rl_history_load();
		init = 1;
	}
	history = *ft_rl_history_gethead();
	ft_rl_term_cur_updatepos(ft_strlen(p));
	if (!history || *history->size <= RL_HISTORY_SIZE)
		ft_lstadd_front(ft_rl_history_gethead(), ft_lstnew(NULL));
	else
		ft_rl_history_recycle();
	line = getline(p);
	ft_rl_history_commit(line);
	tcsetattr(0, TCSANOW, &oldsettings);
	return (line);
}

static char	*getline(const char *p)
{
	t_rl_input	input;
	int			rv;

	input.i = 0;
	input.input = NULL;
	input.prompt = p;
	input.inputlen = 0;
	input.promptlen = ft_strlen(p);
	ft_putstr_fd(p, 1);
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
