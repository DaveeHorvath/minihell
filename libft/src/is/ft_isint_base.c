/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 05:02:40 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/15 21:33:14 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isint_base.c
 */

#include "lft_isint.h"

static inline size_t	maxlen(size_t tsize, t_base base);
static inline int64_t	convert(const char *n, size_t tsize, t_base base);

/** @brief Checks if n is a valid integer representation
 *
 * @param *n String to check
 * @param base Base to check with
 * @retval uint8_t 1 if n is valid, 0 if not
 */
uint8_t	ft_isint_base(const char *n, size_t tsize, t_base base)
{
	const char	*nbrarr = getnbrs(base);
	int64_t		nbr;

	n = trimzeros(n);
	if (!n || ft_strlen(n) > maxlen(tsize, base) + (*n == '+' || *n == '-'))
		return (0);
	nbr = convert(n, tsize, base);
	if ((nbr == -1 && !ft_strequals(n, "-1"))
		|| (nbr == 0 && !ft_strequals(n, "0")))
		return (0);
	if (*n == '+' || *n == '-')
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
		return (tsize * 8 - 1);
	if (base == OCTAL)
		return (tsize * 3 - (tsize / 3) - (tsize == 2 || tsize == 8));
	if (base == DECIMAL)
		return (tsize * 3 - (tsize / 2) - (tsize == 8));
	return (tsize * 8 - 1);
}

static inline int64_t	convert(const char *n, size_t tsize, t_base base)
{
	int64_t	nbr;

	nbr = ft_atoi_base(n, base);
	if ((tsize == 1 && nbr > INT8_MAX)
		|| (tsize == 2 && nbr > INT16_MAX)
		|| (tsize == 4 && nbr > INT32_MAX))
		return (-1);
	if ((tsize == 1 && nbr < INT8_MIN)
		|| (tsize == 2 && nbr < INT16_MIN)
		|| (tsize == 4 && nbr < INT32_MIN))
		return (0);
	return (nbr);
}
