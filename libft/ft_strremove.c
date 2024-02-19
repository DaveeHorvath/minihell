/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:56:22 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:26 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strremove.c
 */

#include "libft.h"

/** @brief Creates a copy of s with all occurences of c removed
 *
 * @param *s String to copy
 * @param c Character to remove
 * @retval char * Pointer to the copy or NULL if the allocation failed
 */
char	*ft_strremove(const char *s, const char c)
{
	size_t	i;
	char	**arr;
	char	*tmp;
	char	*out;

	arr = ft_split(s, c);
	if (!arr)
		return (NULL);
	i = 0;
	out = NULL;
	while (arr[i])
	{
		tmp = ft_strjoin(out, arr[i]);
		out = tmp;
	}
	return (out);
}
