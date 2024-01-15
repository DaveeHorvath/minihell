/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:52:55 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 14:54:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_bzero.c
 */

#include "libft.h"

/** @brief Sets n bytes to 0 starting at s
 *
 * @param s Pointer to start setting at
 * @param n Amount of bytes to set
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(char *)(s + i++) = 0;
}
