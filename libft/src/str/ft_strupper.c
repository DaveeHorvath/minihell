/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:52 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 23:19:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strupper.c
 */

#include "lft_to.h"
#include "lft_str.h"

/** @brief Makes all lowercase characters in s uppercase
 *
 * @param *s String to operate on
 * @retval char * Pointer to s
 */
char	*ft_strupper(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}
