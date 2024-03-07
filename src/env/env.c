/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:46:27 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/06 13:32:29 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int	msh_editenv(char *var, char *val)
{
	t_value	*env;

	env = *msh_getenvhead();
	if (!env)
		return (0);
	while (env)
	{
		if (ft_strequals(env->var, var))
			break ;
		env = env->next;
	}
	if (!env)
		return (0);
	ft_popblk(env->val);
	env->val = ft_push(ft_strdup(val));
	return (1);
}

char	*msh_getenv(char *var)
{
	t_value	*env;

	env = *msh_getenvhead();
	while (env)
	{
		if (ft_strequals(env->var, var))
			return (env->val);
		env = env->next;
	}
	return (NULL);
}

int	msh_unsetenv(char *var)
{
	t_value	**env;
	t_value	*prev;
	t_value	*current;

	env = msh_getenvhead();
	if (!env)
		return (0);
	prev = NULL;
	current = *env;
	while (current)
	{
		if (ft_strequals(current->var, var))
			break ;
		prev = current;
		current = current->next;
	}
	if (!current)
		return (0);
	ft_popblks(3, current, current->var, current->val);
	if (prev)
		prev->next = current->next;
	else
		*env = current->next;
	return (1);
}

int	msh_setenv(char *var, char *val)
{
	t_value	**env;
	t_value	*new;

	if (msh_editenv(var, val))
		return (1);
	new = ft_push(ft_calloc(1, sizeof(t_value)));
	if (!new)
		return (0);
	new->var = ft_push(ft_strdup(var));
	if (val)
		new->val = ft_push(ft_strdup(val));
	env = msh_getenvhead();
	if (!(*env))
	{
		new->total = 1;
		new->next = NULL;
	}
	else
	{
		(*env)->total++;
		new->total = (*env)->total;
		new->next = *env;
	}
	*env = new;
	return (1);
}
