/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:06:35 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 04:48:52 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa.c
 */

#include "lft_to.h"

/** @brief Converts n into a string
 *
 * @param n Integer to be converted into an ascii representation of its value
 * @retval char* Pointer to the allocated string
 * or NULL if the allocation failed
 */
char	*ft_itoa(int64_t n)
{
	return (ft_itoa_base(n, DECIMAL));
}
