/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_altcmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:25:02 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/26 13:42:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void	arrowcmd(t_rl_input *input, char c);
static int	getkey(char *key);

void	ft_rl_altcmd(t_rl_input *input, char redisplay)
{
	char	key[RL_ALTKEY_SIZE];

	if (getkey(key) < 0)
		return ;
	if (*key == '[')
		arrowcmd(input, key[1]);
	else if (*key == KEY_F)
		ft_rl_nextword(input);
	else if (*key == KEY_B)
		ft_rl_prevword(input);
	else if (*key == '>')
		ft_rl_history_setcurrent(*ft_rl_history_gethead());
	else if (*key == '<' )
		ft_rl_history_setcurrent(ft_lstlast(*ft_rl_history_getcurrent(0)));
	else if (*key == KEY_C_R)
		ft_rl_history_search(input, KEY_DOWN);
	if (*key == '>' || *key == '<')
		ft_rl_updateinput(input, (*ft_rl_history_getcurrent(0))->blk, NULL);
	if (redisplay)
		ft_rl_redisplay(input);
}

static void	arrowcmd(t_rl_input *input, char c)
{
	if (c == KEY_LEFT || c == KEY_RIGHT)
		ft_rl_movecursor(input, 1, c);
	else if (c == KEY_UP)
		ft_rl_updateinput(input, ft_rl_history_next(), NULL);
	else if (c == KEY_DOWN)
		ft_rl_updateinput(input, ft_rl_history_prev(), NULL);
}

static int	getkey(char *key)
{
	struct termios	old;
	struct termios	new;
	int				rv;

	tcgetattr(0, &old);
	new = old;
	new.c_cc[VTIME] = 1;
	tcsetattr(0, TCSANOW, &new);
	ft_bzero(key, RL_ALTKEY_SIZE);
	rv = read(0, key, RL_ALTKEY_SIZE);
	tcsetattr(0, TCSANOW, &old);
	return (rv);
}
