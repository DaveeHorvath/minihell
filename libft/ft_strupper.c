/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:52 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 14:09:00 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strupper.c
 */

#include "libft.h"

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
