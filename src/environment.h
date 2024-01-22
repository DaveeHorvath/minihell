/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:15 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/22 15:53:39 by ivalimak         ###   ########.fr       */
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

char	**msh_getenvarr(void);
char	*msh_getenv(char *var);
int		msh_setenv(char *var, char *val);

#endif
