/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 06:27:35 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 06:30:33 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_isint.h"

const char	*getnbrs(t_base base)
{
	static const char	*bin = "01";
	static const char	*oct = "01234567";
	static const char	*dec = "0123456789";
	static const char	*hex = "0123456789ABCDEF";

	if (base == BINARY)
		return (bin);
	if (base == OCTAL)
		return (oct);
	if (base == DECIMAL)
		return (dec);
	return (hex);
}

char	*trimzeros(const char *n)
{
	static char	out[64];
	size_t		i;

	if (!n)
		return (NULL);
	i = 0;
	if (*n == '+' || *n == '-')
		out[i++] = *n++;
	while (*n == '0' && *(n + 1))
		n++;
	ft_strlcpy(&out[i], n, ft_strlen(n) + 1);
	return (out);
}

uint8_t	inbase(const char *nbrarr, const uint8_t c)
{
	while (*nbrarr)
	{
		if (*nbrarr++ == ft_toupper(c))
			return (1);
	}
	return (0);
}
