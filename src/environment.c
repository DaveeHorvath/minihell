/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:46:27 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/22 17:21:05 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static t_value	**msh_getenvhead(void)
{
	static t_value	*env;

	return (&env);
}

char	**msh_getenvarr(void)
{
	char	**out;
	t_value	*env;
	size_t	i;

	env = *msh_getenvhead();
	if (!env)
		return (NULL);
	out = ft_push(ft_alloc((env->total + 1) * sizeof(char *)));
	if (!out)
		return (NULL);
	i = 0;
	while (env)
	{
		out[i] = ft_push(ft_strsjoin(env->var, env->val, '='));
		if (!out[i++])
			return (NULL);
		env = env->next;
	}
	out[i++] = NULL;
	ft_popn(i);
	return (out);
}

char	*msh_getenv(char *var)
{
	t_value	*env;

	env = *msh_getenvhead();
	while (env)
	{
		if (!ft_strncmp(env->var, var, ft_strlen(var)))
			return (env->val);
		env = env->next;
	}
	return (NULL);
}

int	msh_setenv(char *var, char *val)
{
	t_value	**env;
	t_value	*new;

	new = ft_push(ft_alloc(sizeof(t_value)));
	if (!new)
		return (0);
	new->var = ft_push(ft_strdup(var));
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
