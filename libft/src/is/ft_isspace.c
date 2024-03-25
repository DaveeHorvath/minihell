/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:42:20 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 05:10:46 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isspace.c
 */

#include "lft_is.h"

/** @brief Checks if c is a whitespace character
 *
 * @param c Character to check
 * @retval uint8_t 1 if c is whitespace, 0 if not
 */
uint8_t	ft_isspace(uint8_t c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}
