/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:03:50 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 00:13:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_tolower.c
 */

#include "lft_is.h"
#include "lft_to.h"

/** @brief Turns an uppercase character to lowercase
 *
 * @param c Character to check
 * @retval c + 32 if c is uppercase, c if not
 */
uint8_t	ft_tolower(uint8_t c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}
