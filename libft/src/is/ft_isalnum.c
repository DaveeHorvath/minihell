/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:00:41 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 05:10:06 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isalnum.c
 */

#include "lft_is.h"

/** @brief Checks if c is an alphanumeric character
 *
 * @param c Character to check
 * @retval uint8_t 1 if c is alphanumeric, 0 if not
 */
uint8_t	ft_isalnum(uint8_t c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
