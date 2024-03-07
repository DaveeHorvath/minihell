/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:13:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/06 12:25:02 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_value	**msh_getenvhead(void)
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
		if (env->val)
			out[i] = ft_push(ft_strsjoin(env->var, env->val, '='));
		else
			out[i] = ft_push(ft_strjoin(env->var, "="));
		if (!out[i++])
			return (NULL);
		env = env->next;
	}
	out[i] = NULL;
	return (out);
}

void	msh_cpyenv(char **env)
{
	char	*var;
	char	*val;

	if (!env)
		return ;
	while (*env)
	{
		var = ft_substr(*env, 0, ft_strclen(*env, '='));
		val = ft_strchr(*env, '=');
		if (val)
			val++;
		msh_setenv(var, val);
		env++;
	}
}
