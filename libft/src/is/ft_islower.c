/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:00:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 05:10:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_islower
 */

#include "lft_is.h"

/** @brief Checks if c is an lowercase character
 *
 * @param c Character to check
 * @retval uint8_t 1 if c is lowercase, 0 if not
 */
uint8_t	ft_islower(uint8_t c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
