/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:00:41 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:18 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isalnum.c
 */

#include "libft.h"

/** @brief Checks if c is an alphanumeric character
 *
 * @param c Character to check
 * @retval int 1 if c is alphanumeric, 0 if not
 */
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) > 0 || ft_isdigit(c) > 0)
		return (1);
	return (0);
}
