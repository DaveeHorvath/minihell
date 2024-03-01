/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_historyfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:44:00 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/24 19:56:24 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "ft_readline.h"

void	ft_rl_history_load(void)
{
	int		fd;
	char	*line;
	char	*fname;

	fname = ft_strsjoin(msh_getenv("HOME"), RL_HFNAME, '/');
	if (!fname)
		return ;
	fd = open(fname, O_RDONLY);
	line = ft_strtrim(get_next_line(fd), "\n");
	while (line)
	{
		ft_lstadd_front(ft_rl_history_gethead(), ft_lstnew(line));
		line = ft_strtrim(get_next_line(fd), "\n");
	}
	close(fd);
}

void	ft_rl_history_save(void)
{
	int		fd;
	char	*fname;
	t_list	*history;

	fname = ft_strsjoin(msh_getenv("HOME"), RL_HFNAME, '/');
	if (!fname)
		return ;
	fd = open(fname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		return ;
	history = ft_lstlast(*ft_rl_history_gethead());
	while (history)
	{
		if (*(char *)history->blk)
			ft_putendl_fd(history->blk, fd);
		history = history->prev;
	}
	close(fd);
}
