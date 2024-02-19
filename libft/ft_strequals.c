/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 07:36:40 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:25 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strequals.c
 */

#include "libft.h"

/** @brief Checks if s1 and s2 are the same
 *
 * @param *s1 First string
 * @param *s2 Second string
 * @retval int 1 if s1 and s2 are the same or 0 if they are not
 */
int	ft_strequals(const char *s1, const char *s2)
{
	size_t	len1;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	if (ft_strncmp(s1, s2, len1))
		return (0);
	if (len1 != ft_strlen(s2))
		return (0);
	return (1);
}
