/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:13:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/23 11:28:13 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_value	**msh_getenvhead(void)
{
	static t_value	*env;

	return (&env);
}
