/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:07:56 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 05:10:25 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isascii.c
 */

#include "lft_is.h"
#include "lft_limits.h"

/** @brief Checks if c is an ascii character
 *
 * @param c Character to check
 * @retval uint8_t 1 if c is ascii, 0 if not
 */
uint8_t	ft_isascii(uint8_t c)
{
	if (c <= ASCII_MAX)
		return (1);
	return (0);
}
