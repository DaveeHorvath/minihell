/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_altcmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:25:02 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/11 13:39:49 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void	arrowcmd(t_rl_input *input);
static void	addmeta(t_rl_input *input);
static void	getmeta(char *metachar);

void	ft_rl_altcmd(t_rl_input *input, char redisplay)
{
	char	c;

	if (read(0, &c, 1) < 1)
		return ;
	if (c == '[')
		arrowcmd(input);
	else if (c == KEY_ALT)
		addmeta(input);
	else if (c == KEY_F)
		ft_rl_nextword(input);
	else if (c == KEY_B)
		ft_rl_prevword(input);
	else if (c == '>')
		ft_rl_history_setcurrent(*ft_rl_history_gethead());
	else if (c == '<' )
		ft_rl_history_setcurrent(ft_lstlast(*ft_rl_history_getcurrent(0)));
	if (c == '>' || c == '<')
		ft_rl_updateinput(input, (*ft_rl_history_getcurrent(0))->blk);
	if (redisplay)
		ft_rl_redisplay(input);
}

static void	arrowcmd(t_rl_input *input)
{
	char	c;

	if (read(0, &c, 1) < 1)
		return ;
	if (c == KEY_LEFT || c == KEY_RIGHT)
		ft_rl_movecursor(input, 1, c);
	else if (c == KEY_UP)
		ft_rl_updateinput(input, ft_rl_history_next());
	else if (c == KEY_DOWN)
		ft_rl_updateinput(input, ft_rl_history_prev());
}

static void	addmeta(t_rl_input *input)
{
	size_t	i;
	size_t	charlen;
	char	metachar[RL_METACHAR_SIZE];
	int		row;
	int		col;

	getmeta(metachar);
	charlen = ft_strlen(metachar);
	if (charlen == 2 && *metachar == '[')
		ft_rl_addchar(input, '0');
	else if (charlen == 3 && *metachar == '[')
		ft_rl_addchar(input, '[');
	else
		ft_rl_addchar(input, *metachar);
	i = 1;
	while (i < charlen)
		ft_rl_addchar(input, metachar[i++]);
	ft_rl_term_cur_getpos(&row, &col, 0);
	col += charlen;
	if (col == (int)charlen + 1)
		col += input->promptlen;
	ft_rl_term_cur_inputstart();
	ft_putstr_fd(TERM_CLEAR_END, 1);
	ft_putstr_fd(input->input, 1);
	ft_rl_term_cur_setpos(row, col);
}

static void	getmeta(char *metachar)
{
	struct termios	old;
	struct termios	new;

	tcgetattr(0, &old);
	new = old;
	new.c_cc[VTIME] = 1;
	tcsetattr(0, TCSANOW, &new);
	ft_bzero(metachar, RL_METACHAR_SIZE);
	if (read(0, metachar, RL_METACHAR_SIZE) < 0)
		return ;
	tcsetattr(0, TCSANOW, &old);
}
