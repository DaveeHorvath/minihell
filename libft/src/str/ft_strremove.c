/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:56:22 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 23:18:53 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strremove.c
 */

#include "lft_gc.h"
#include "lft_str.h"

/** @brief Creates a copy of s with all occurences of c removed
 *
 * @param *s String to copy
 * @param c Character to remove
 * @retval char * Pointer to the copy or NULL if the allocation failed
 */
char	*ft_strremove(const char *s, const uint8_t c)
{
	size_t	i;
	char	**arr;
	char	*out;

	arr = ft_pusharr(ft_split(s, c));
	if (!arr)
		return (NULL);
	i = 0;
	out = NULL;
	while (arr[i])
	{
		out = ft_strjoin(out, arr[i]);
		ft_popblk(arr[i++]);
	}
	ft_popblk(arr);
	return (out);
}
