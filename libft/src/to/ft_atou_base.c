/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:13:23 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/16 03:33:59 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atou_base.c
 */

#include "lft_is.h"
#include "lft_to.h"

static inline uint8_t	inbase(const uint8_t c, t_base base);
static inline uint8_t	getbn(t_base base);

/** @brief Converts s to a 64-bit unsigned integer value
 *
 * @param *s String to convert
 * @param base Base to convert in
 * @retval uint64_t Converted value of s
 */
uint64_t	ft_atou_base(const char *s, t_base base)
{
	uint64_t	out;
	uint8_t		bn;

	out = 0;
	bn = getbn(base);
	while (ft_isspace(*s))
		s++;
	if (*s == '+')
		s++;
	while (inbase(*s, base))
	{
		if (out > UINT64_MAX / bn)
			return (0);
		if (base != HEX || ft_isdigit(*s))
			out = out * bn + (*s++ - '0');
		else
			out = out * bn + (ft_toupper(*s++) - 'A' + 10);
	}
	return (out);
}

static inline uint8_t	inbase(const uint8_t c, t_base base)
{
	if (base == BINARY)
		return (c == '0' || c == '1');
	if (base == OCTAL)
		return (ft_isdigit(c) && c < '8');
	if (base == DECIMAL)
		return (ft_isdigit(c));
	return (ft_isdigit(c) || (ft_toupper(c) >= 'A' && ft_toupper(c) <= 'F'));
}

static inline uint8_t	getbn(t_base base)
{
	if (base == BINARY)
		return (2);
	if (base == OCTAL)
		return (8);
	if (base == DECIMAL)
		return (10);
	return (16);
}
