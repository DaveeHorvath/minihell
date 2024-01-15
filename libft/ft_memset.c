/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:33:24 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 13:08:49 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memset.c
 */

#include "libft.h"

/** @brief Sets n bytes to c, starting from b
 *
 * @param *b Pointer to the start of the memory area
 * @param c value to set for each byte
 * @param n Amount of bytes to set
 * @retval void * Pointer to the start of the memory area
 */
void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(char *)(b + i++) = (unsigned char)c;
	return (b);
}
