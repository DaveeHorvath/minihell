/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuint_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 05:49:41 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/16 05:05:30 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isuint_base.c
 */

#include "lft_isint.h"

static inline uint64_t	convert(const char *n, size_t tsize, t_base base);
static inline size_t		maxlen(size_t tsize, t_base base);

/** @brief Checks if n is a valid unsigned integer representation
 *
 * @param *n String to check
 * @param base Base to check with
 * @retval uint8_t 1 if n is valid, 0 if not
 */
uint8_t	ft_isuint_base(const char *n, size_t tsize, t_base base)
{
	const char	*nbrarr = getnbrs(base);
	uint64_t	nbr;

	n = trimzeros(n);
	if (!n || ft_strlen(n) > maxlen(tsize, base) + (*n == '+'))
		return (0);
	nbr = convert(n, tsize, base);
	if (nbr == 0 && !ft_strequals(n, "0"))
		return (0);
	if (*n == '+')
		n++;
	while (*n)
	{
		if (!inbase(nbrarr, *n++))
			return (0);
	}
	return (1);
}

static inline size_t	maxlen(size_t tsize, t_base base)
{
	if (base == BINARY)
		return (tsize * 8);
	if (base == OCTAL)
		return (tsize * 3 - (tsize / 3));
	if (base == DECIMAL)
		return (tsize * 3 - (tsize / 2));
	return (tsize * 2);
}

static inline uint64_t	convert(const char *n, size_t tsize, t_base base)
{
	uint64_t	nbr;

	nbr = ft_atou_base(n, base);
	if ((tsize == 1 && nbr > UINT8_MAX)
		|| (tsize == 2 && nbr > UINT16_MAX)
		|| (tsize == 4 && nbr > UINT32_MAX))
		return (0);
	return (nbr);
}
