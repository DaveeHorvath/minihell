/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:51:41 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 13:27:48 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strjoin.c
 */

#include "libft.h"

/** @brief Allocates and returns a new string resulting 
 * from combining s1 and s2
 *
 * @param *s1 String to add s2 to
 * @param *s2 String to add to s1
 * @retval char * Pointer to the new string or NULL if the allocation failed
 * or s2 was NULL
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*out;

	if (!s2)
		return (NULL);
	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ft_pushn(2, s1, s2);
	out = ft_calloc(len1 + len2 + 1, sizeof(char));
	ft_popn(1 + (s1 != NULL));
	if (!out)
		return (NULL);
	if (s1)
		ft_strlcpy(out, s1, len1 + 1);
	ft_strlcpy((out + len1), s2, len2 + 1);
	return (out);
}
