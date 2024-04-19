/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:29:24 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/18 13:49:30 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"
#include "parser.h"
#include <signal.h>

static inline struct sigaction	*getoldactions(void);
static inline void				_enable(uint8_t sigs);
static inline void				_disable(uint8_t sigs);

void	ft_rl_signal(uint8_t action, uint8_t sigs)
{
	static uint8_t	status = RL_SIG_DISABLE;

	if (action == RL_SIG_ENABLE && status != RL_SIG_ENABLE)
		_enable(sigs);
	else if (status != RL_SIG_DISABLE)
		_disable(sigs);
	status = action;
}

void	ft_rl_sigaction(int32_t signal)
{
	if (signal == SIGINT && heredoc_stopper(NULL, 0))
		ft_rl_heredoc_hook(ft_rl_getcurinput());
	else if (signal == SIGINT)
		ft_rl_dcl(ft_rl_getcurinput());
	else if (signal == SIGWINCH)
		ft_rl_resize_hook(ft_rl_getcurinput());
	else if (signal == SIGQUIT)
		;
}

static inline struct sigaction	*getoldactions(void)
{
	static struct sigaction	oldactions[3];

	return (oldactions);
}

static inline void	_enable(uint8_t sigs)
{
	struct sigaction		*oldactions;
	static struct sigaction	newaction;

	if (!newaction.sa_handler)
	{
		newaction.sa_handler = ft_rl_sigaction;
		sigemptyset(&newaction.sa_mask);
		newaction.sa_flags = 0;
	}
	oldactions = getoldactions();
	if (sigs & RL_SIG_INT)
		sigaction(SIGINT, &newaction, &oldactions[0]);
	if (sigs & RL_SIG_WINCH)
		sigaction(SIGWINCH, &newaction, &oldactions[1]);
	if (sigs & RL_SIG_QUIT)
		sigaction(SIGQUIT, &newaction, &oldactions[2]);
}

static inline void	_disable(uint8_t sigs)
{
	struct sigaction	*oldactions;

	oldactions = getoldactions();
	if (sigs & RL_SIG_INT)
		sigaction(SIGINT, &oldactions[0], NULL);
	if (sigs & RL_SIG_WINCH)
		sigaction(SIGWINCH, &oldactions[1], NULL);
	if (sigs & RL_SIG_QUIT)
		sigaction(SIGQUIT, &oldactions[1], NULL);
}
