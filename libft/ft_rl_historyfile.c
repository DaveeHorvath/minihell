/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_historyfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:44:00 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/05 14:39:14 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rl_history_load(void)
{
	int		fd;
	char	*line;
	char	*fname;

	fname = ft_strsjoin(getenv("HOME"), RLHFNAME, '/');
	if (!fname)
		return ;
	fd = open(fname, O_RDONLY);
	line = ft_strtrim(get_next_line(fd), "\n");
	while (line)
	{
		ft_lstadd_back(ft_rl_history_gethead(), ft_lstnew(line));
		line = ft_strtrim(get_next_line(fd), "\n");
	}
	close(fd);
}

void	ft_rl_history_save(void)
{
	int		fd;
	char	*fname;
	t_list	*history;

	fname = ft_strsjoin(getenv("HOME"), RLHFNAME, '/');
	if (!fname)
		return ;
	fd = open(fname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		return ;
	history = *ft_rl_history_gethead();
	if (history)
		history = history->next;
	while (history)
	{
		ft_putendl_fd(history->blk, fd);
		history = history->next;
	}
	close(fd);
}
