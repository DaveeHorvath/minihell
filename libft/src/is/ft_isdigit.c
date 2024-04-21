/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:59:25 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 19:08:50 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isdigit.c
 */

#include "lft_is.h"

/** @brief Checks if c is a numerical character
 *
 * @param c Character to check
 * @retval uint8_t 1 if c is a digit, 0 if not
 */
uint8_t	ft_isdigit(uint8_t c)
{
	return (c >= '0' && c <= '9');
}
