/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:50:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 04:37:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi_base.c
 */

#include "lft_is.h"
#include "lft_to.h"

static inline int64_t	addbase(const int64_t n, const uint8_t c, t_base base);
static inline int8_t	inbase(const uint8_t c, t_base base);
static inline int8_t	getbn(t_base base);

/** @brief Converts s to a 64-bit integer value
 *
 * @param *s String to convert
 * @param base Base to convert in
 * @retval int64_t Converted value of s
 */
int64_t	ft_atoi_base(const char *s, t_base base)
{
	int64_t	out;
	int8_t	bn;
	int8_t	n;

	n = 1;
	out = 0;
	bn = getbn(base);
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		n = -n;
	if (*s == '-' || *s == '+')
		s++;
	while (inbase(*s, base))
	{
		if (out > INT64_MAX / bn
			|| (out == INT64_MAX / bn && addbase(out, *s, base) - (n < 0) < 0))
		{
			if (n < 0)
				return (0);
			return (-1);
		}
		out = addbase(out, *s++, base);
	}
	return (out * n);
}

static inline int64_t	addbase(const int64_t n, const uint8_t c, t_base base)
{
	if (base != HEX || ft_isdigit(c))
		return (n * getbn(base) + (c - '0'));
	return (n * 16 + (ft_toupper(c) - 'A' + 10));
}

static inline int8_t	inbase(const uint8_t c, t_base base)
{
	if (base == BINARY)
		return (c == '0' || c == '1');
	if (base == OCTAL)
		return (ft_isdigit(c) && c < '8');
	if (base == DECIMAL)
		return (ft_isdigit(c));
	return (ft_isdigit(c) || (ft_toupper(c) >= 'A' && ft_toupper(c) <= 'F'));
}

static inline int8_t	getbn(t_base base)
{
	if (base == BINARY)
		return (2);
	if (base == OCTAL)
		return (8);
	if (base == DECIMAL)
		return (10);
	return (16);
}
