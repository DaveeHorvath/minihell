/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:02:29 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 00:14:12 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_toupper.c
 */

#include "lft_is.h"
#include "lft_to.h"

/** @brief Turns a lowercase character to uppercase
 *
 * @param c Character to check
 * @retval c - 32 if c is lowercase, c if not
 */
uint8_t	ft_toupper(uint8_t c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}
