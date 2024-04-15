/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:20:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 23:20:55 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strchr.c
 */

#include "lft_mem.h"
#include "lft_str.h"

/** @brief Finds the first occurence of c in s
 *
 * @param *s String to look for c in
 * @param c Character to look for
 * @retval char * Pointer to the first occurence of c or
 * NULL if c was not found
 */
char	*ft_strchr(const char *s, const uint8_t c)
{
	return (ft_memchr(s, c, ft_strlen(s)));
}
