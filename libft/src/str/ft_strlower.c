/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:36:27 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 23:18:27 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlower
 */

#include "lft_to.h"
#include "lft_str.h"

/** @brief Makes all uppercase characters in s lowercase
 *
 * @param *s String to operate on
 * @retval char * Pointer to s
 */
char	*ft_strlower(char *s)
{
	size_t	i;

	if (!s)
		return (s);
	i = 0;
	while (s[i])
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}
