/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:33:01 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/22 17:25:18 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_pwd(void)
{
	char	*path;

	path = msh_getenv("PWD");
	if (!path)
		return (1);
	ft_putstr_fd(path, 1);
	return (0);
}
