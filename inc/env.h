/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:15 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/06 12:20:29 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "libft.h"

typedef struct s_value
{
	char			*var;
	char			*val;
	struct s_value	*next;
	size_t			total;
}	t_value;

// env.c
char	*msh_getenv(char *var);
int		msh_unsetenv(char *var);
int		msh_setenv(char *var, char *val);

// envutils.c
t_value	**msh_getenvhead(void);
char	**msh_getenvarr(void);
void	msh_cpyenv(char **env);

#endif
