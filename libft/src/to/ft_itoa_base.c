/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:38:37 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/21 07:41:03 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa_base.c
 */

#include "lft_gc.h"
#include "lft_to.h"
#include "lft_mem.h"
#include "lft_nbr.h"
#include "lft_str.h"

static inline char	*basemin(t_base base);
static inline int8_t	getdiv(t_base base);

/** @brief Converts n into a string
 *
 * @param n Integer to be converted into an ascii representation of its value
 * @param base Base to convert in
 * @retval char* Pointer to the allocated string
 * or NULL if the allocation failed
 */
char	*ft_itoa_base(int64_t n, t_base base)
{
	size_t				i;
	int8_t				neg;
	int8_t				div;
	char				*out;
	static const char	nbrarr[16] = "0123456789ABCDEF";

	if (n == INT64_MIN)
		return (basemin(base));
	i = ft_intlen(n, base);
	out = ft_calloc(i-- + 1, sizeof(*out));
	if (!out)
		return (NULL);
	div = getdiv(base);
	neg = n < 0;
	if (neg)
		n = -n;
	while (n > div - 1)
	{
		out[i--] = nbrarr[n % div];
		n /= div;
	}
	out[i--] = nbrarr[n];
	if (neg)
		out[i] = '-';
	return (out);
}

static inline char	*basemin(t_base base)
{
	if (base == BINARY)
		return (ft_strjoin("-1",
				ft_memset(ft_calloc(64, sizeof(char)), '0', 63)));
	if (base == OCTAL)
		return (ft_strdup("-1000000000000000000000"));
	if (base == DECIMAL)
		return (ft_strdup("-9223372036854775808"));
	return (ft_strdup("-8000000000000000"));
}

static inline int8_t	getdiv(t_base base)
{
	if (base == BINARY)
		return (2);
	if (base == OCTAL)
		return (8);
	if (base == DECIMAL)
		return (10);
	return (16);
}
