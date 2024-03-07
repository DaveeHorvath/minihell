/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:01:05 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/04 13:43:52 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"

static t_alias	**gethead(void)
{
	static t_alias	*aliases;

	return (&aliases);
}

static int	msh_editalias(char *alias, char *command)
{
	t_alias	*aliases;

	aliases = *gethead();
	if (!aliases)
		return (0);
	while (aliases)
	{
		if (ft_strequals(aliases->alias, alias))
			break ;
		aliases = aliases->next;
	}
	if (!aliases)
		return (0);
	ft_popblk(aliases->command);
	aliases->command = ft_push(ft_strdup(command));
	return (1);
}

char	*msh_getalias(char *alias)
{
	t_alias	*aliases;

	aliases = *gethead();
	while (aliases)
	{
		if (ft_strequals(aliases->alias, alias))
			return (aliases->command);
		aliases = aliases->next;
	}
	return (NULL);
}

int		msh_unsetalias(char *alias)
{
	t_alias	**aliases;
	t_alias	*current;
	t_alias	*prev;

	aliases = gethead();
	if (!aliases)
		return (0);
	prev = NULL;
	current = *aliases;
	while (current)
	{
		if (ft_strequals(current->alias, alias))
			break ;
		prev = current;
		current = current->next;
	}
	if (!current)
		return (0);
	ft_popblks(3, current, current->alias, current->command);
	if (prev)
		prev->next = current->next;
	else
		*aliases = current->next;
	return (1);
}

int		msh_setalias(char *alias, char *command)
{
	t_alias	**aliases;
	t_alias	*newalias;

	if (msh_editalias(alias, command))
		return (1);
	newalias = ft_push(ft_calloc(1, sizeof(t_alias)));
	if (!newalias)
		return (0);
	newalias->alias = ft_push(ft_strdup(alias));
	newalias->command = ft_push(ft_strdup(command));
	aliases = gethead();
	if (*aliases)
		newalias->next = *aliases;
	*aliases =  newalias;
	return (1);
}
