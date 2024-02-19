/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:31:15 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:26 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strrev.c
 */

#include "libft.h"

/** @brief Reverses the string s
 *
 * @param *s String to reverse
 * @retval char * Pointer to the start of s
 */
char	*ft_strrev(char *s)
{
	char	tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i++] = s[j];
		s[j--] = tmp;
	}
	return (s);
}
