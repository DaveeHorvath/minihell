/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 06:40:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/15 20:39:40 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isuint.c
 */

#include "lft_is.h"

/** @brief Checks if n is a valid unsigned integer representation
 *
 * @param *n String to check
 * @retval uint8_t 1 if n is valid, 0 if not
 */
uint8_t	ft_isuint(const char *n, size_t tsize)
{
	return (ft_isuint_base(n, tsize, DECIMAL));
}
