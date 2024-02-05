/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:11:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/03 20:58:05 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_readline.c
 */

#include "libft.h"

static char	*readinput(const char *p);
static char	*addchar(char *s, char c, size_t pos);
static char	*removechar(char *s, size_t i);

/** @brief man 3 readline
 *
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

	if (!init)
	{
		ft_rl_history_load();
		init = 1;
	}
	tcgetattr(0, &oldsettings);
	newsettings = oldsettings;
	newsettings.c_lflag &= (~ICANON & ~ECHO);
	tcsetattr(0, TCSANOW, &newsettings);
	history = *ft_rl_history_gethead();
	if (!history || *history->size <= RL_HISTORY_SIZE)
		ft_lstadd_front(ft_rl_history_gethead(), ft_lstnew(NULL));
	else
		ft_rl_history_recycle();
	line = readinput(p);
	ft_rl_history_commit(line);
	tcsetattr(0, TCSANOW, &oldsettings);
	return (line);
}

static char	*readinput(const char *p)
{
	size_t	i;
	char	c;
	char	*line;
	int		rv;

	i = 0;
	line = NULL;
	ft_printf("%s", p);
	rv = read(0, &c, 1);
	while (rv > 0)
	{
		if (c == KEY_RET)
		{
			ft_rl_setcurcol(ft_strlen(p) + i + 1);
			ft_putchar_fd('\n', 1);
			if (line && !*line)
			{
				ft_popblk(line);
				line = NULL;
			}
			return (line);
		}
		if (c == KEY_ALT)
			ft_rl_altcmd(&i, (char *)p, &line);
		else if (c >= KEY_C_A && c <= KEY_C_Z)
			ft_rl_ctrlcmd(c, &i, (char *)p, &line);
		else
		{
			if (c != KEY_DEL)
				line = addchar(line, c, i++);
			else
			{
				line = removechar(line, i);
				if (i)
					i--;
			}
			ft_rl_history_update(line);
		}
		ft_rl_setcurcol(ft_strlen(p) + 1);
		ft_printf("%s", TERM_CLEAR_END);
		if (line)
			ft_putstr_fd(line, 1);
		ft_rl_setcurcol(ft_strlen(p) + i + 1);
		rv = read(0, &c, 1);
	}
	return (NULL);
}

static char	*addchar(char *s, char c, size_t i)
{
	char	*out;

	if (!s)
	{
		out = ft_push(ft_calloc(2, sizeof(char)));
		if (out)
			*out = c;
		return (out);
	}
	out = ft_push(ft_calloc(ft_getblksize(s) + 1, sizeof(char)));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s, i + 1);
	out[i] = c;
	ft_strlcpy(&out[i + 1], &s[i], ft_strlen(&s[i]) + 1);
	ft_popblk(s);
	return (out);
}

static char	*removechar(char *s, size_t i)
{
	char	*out;

	if (!s || ft_getblksize(s) == 1)
		return (NULL);
	out = ft_push(ft_calloc(ft_getblksize(s) + 1, sizeof(char)));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s, i);
	ft_strlcpy(&out[i - 1], &s[i], ft_strlen(&s[i]) + 1);
	ft_popblk(s);
	return (out);
}
