/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:31:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:25 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlcat.c
 */

#include "libft.h"

/** @brief catenates src to dst, NUL terminating the result
 *
 * @param *dst String to catenate to
 * @param *src String to catenate from
 * @param dstsize Total size of the destination block
 * @retval size_t Length of the string the function tried to create
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	if (dstsize < dstlen)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (dstlen + i < dstsize - 1 && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + ft_strlen(src));
}
