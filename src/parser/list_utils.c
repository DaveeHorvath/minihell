/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:26:35 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/22 23:40:12 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}

void	ft_lstaddback(t_list **list, t_list *new)
{
	t_list	*current;

	current = *list;
	if (!*list)
	{
		*list = new;
		return ;
	}
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = new;
	*list = current;
}

int	append(t_list **cmds, char *s, int old_i, int i)
{
	t_list	*new;
	char	*cont;

	cont = ft_substr(s, old_i, i - old_i);
	if (!cont)
		return (0);
	new = ft_lstnew(cont);
	if (!new)
	{
		free(cont);
		return (0);
	}
	ft_lstaddback(cmds, new);
	return (1);
}
