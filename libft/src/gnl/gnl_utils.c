/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:44:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 23:10:43 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file gnl_utils.c
 */

#include "lft_gc.h"
#include "lft_str.h"
#include "lft_gnl_internal.h"

/** @brief Copies n characters from src to dst and NUL terminates dst
 *
 * @param *dst String to copy to
 * @param *src String to copy from
 * @param n Amount of characters to copy
 * @retval char* Pointer to the start of dst or NULL if dst is empty
 */
char	*bufshift(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	src = dst + n;
	while (*src)
		*src++ = '\0';
	if (*dst)
		return (dst);
	return (NULL);
}

/** @brief Catenates characters from buf to out
 *
 * Joins the characters from buf, until the first newline, to out
 * @param *buf String to catenate from
 * @param **out Address of string to catenate to
 * @retval char* Address of buf or NULL if the allocation failed
 */
char	*bufcopy(char *buf, char **out)
{
	size_t	linelen;
	size_t	buflen;
	char	*cpy;
	char	*tmp;

	buflen = ft_strlen(buf);
	linelen = ft_strclen(buf, '\n');
	if (linelen < buflen)
		linelen++;
	ft_push(*out);
	cpy = ft_calloc(linelen + 1, sizeof(char));
	if (*out)
		ft_pop();
	ft_strlcpy(cpy, buf, linelen + 1);
	bufshift(buf, &buf[linelen], buflen - linelen);
	if (!*out)
		tmp = cpy;
	else
		tmp = ft_strjoin(*out, cpy);
	if (!cpy)
		return (NULL);
	*out = tmp;
	return (buf);
}
