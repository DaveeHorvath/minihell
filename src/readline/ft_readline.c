/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:17:01 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/27 14:32:55 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static inline size_t	getplen(const char *prompt);
static inline char	*getline(const char *prompt);

char	*ft_readline(const char *prompt)
{
	struct termios	old;
	struct termios	new;
	char			*out;

	ft_rl_init();
	tcgetattr(0, &old);
	new = old;
	new.c_lflag &= (~ICANON & ~ECHO);
	tcsetattr(0, TCSANOW, &new);
	out = getline(prompt);
	tcsetattr(0, TCSANOW, &old);
	return (out);
}

static inline size_t	getplen(const char *prompt)
{
	size_t	len;

	len = 0;
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
		len++;
	}
	return (len);
}

static inline char	*getline(const char *prompt)
{
	t_rl_input	input;
	char		*out;

	input = (t_rl_input){.prompt = prompt, .plen = getplen(prompt)};
	input.cursor = ft_rl_getcursor(&input);
	input.cursor->col += input.plen;
	ft_putstr_fd(prompt, 1);
	while (ft_rl_getinput(&input))
		;
	if (!input.head)
		return (NULL);
	out = NULL;
	input.current = input.head;
	while (input.current)
	{
		out = ft_strjoin(out, input.current->word);
		input.current = input.current->next;
	}
	return (out);
}
