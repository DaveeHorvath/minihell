/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:22:58 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 04:50:42 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_uitoa.c
 */

#include "lft_to.h"

/** @brief Converts n into a string
 *
 * @param n Unsigned integer to be converted into
 * an ascii representation of its value
 * @retval char* Pointer to the allocated string
 * or NULL if the allocation failed
 */
char	*ft_utoa(uint64_t n)
{
	return (ft_utoa_base(n, DECIMAL));
}
