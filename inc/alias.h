/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:58:18 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/04 13:55:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIAS_H
# define ALIAS_H
# include "libft.h"

typedef struct s_alias
{
	char			*alias;
	char			*command;
	struct s_alias	*next;
}	t_alias;

// alias.c
char	*msh_getalias(char *alias);
int		msh_unsetalias(char *alias);
int		msh_setalias(char *alias, char *command);

#endif
