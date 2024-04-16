/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:25:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/21 07:41:57 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_uitoa_base.c
 */

#include "lft_gc.h"
#include "lft_to.h"
#include "lft_nbr.h"

static inline uint8_t	getdiv(t_base base);

/** @brief Converts n into a string
 *
 * @param n Unsigned integer to be converted into an
 * ascii representation of its value
 * @param base Base to convert int
 * @retval char* Pointer to the allocated string
 * or NULL if the allocation failed
 */
char	*ft_utoa_base(uint64_t n, t_base base)
{
	size_t				i;
	uint8_t				div;
	char				*out;
	static const char	nbrarr[16] = "0123456789ABCDEF";

	i = ft_uintlen(n, base);
	out = ft_calloc(i-- + 1, sizeof(*out));
	if (!out)
		return (NULL);
	div = getdiv(base);
	while (n > div - 1U)
	{
		out[i--] = nbrarr[n % div];
		n /= div;
	}
	out[i] = nbrarr[n];
	return (out);
}

static inline uint8_t	getdiv(t_base base)
{
	if (base == BINARY)
		return (2);
	if (base == OCTAL)
		return (8);
	if (base == DECIMAL)
		return (10);
	return (16);
}
