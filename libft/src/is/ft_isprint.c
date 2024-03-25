/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:02:30 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 05:10:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isprint.c
 */

#include "lft_is.h"

/** @brief Checks if c is a printable character
 *
 * @param c Character to check
 * @retval uint8_t 1 if c is printable, 0 if not
 */
uint8_t	ft_isprint(uint8_t c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
