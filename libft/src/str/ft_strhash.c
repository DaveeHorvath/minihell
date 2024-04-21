/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:34:55 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 03:16:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_str.h"
#include "lft_math.h"

uint64_t	ft_strhash(const char *s, const uint64_t salt, const size_t size)
{
	uint64_t	hash;
	size_t		slen;
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	hash = 0;
	slen = ft_strlen(s);
	while (i < slen)
	{
		hash += ft_upow(salt, slen - i + 1) * s[i];
		hash %= size;
		i++;
	}
	return (hash);
}
