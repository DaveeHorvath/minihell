/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 06:36:54 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/15 20:39:17 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isint.c
 */

#include "lft_is.h"

/** @breif Checks if n is a valid integer representation
 *
 * @param *n String to check
 * @retval uint8_t 1 if n is valid, 0 if not
 */
uint8_t	ft_isint(const char *n, size_t tsize)
{
	return (ft_isint_base(n, tsize, DECIMAL));
}
