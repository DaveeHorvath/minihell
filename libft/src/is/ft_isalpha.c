/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:41:00 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 19:08:15 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file
 */

#include "lft_is.h"

/** @brief Checks if is an alphabetical character
 *
 * @param c Character to check
 * @retval uint8_t 1 if c is alphabetical, 0 if not
 */
uint8_t	ft_isalpha(uint8_t c)
{
	return (ft_isupper(c) || ft_islower(c));
}
