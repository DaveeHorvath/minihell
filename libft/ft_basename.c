/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:29:46 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/02 09:51:17 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_basename(const char *path)
{
	char	*out;
	char	*tmp;

	ft_push((void *)path);
	out = ft_strtrim(path, "/");
	ft_popblk((void *)path);
	if (!out)
		return (NULL);
	tmp = ft_strrchr(out, '/');
	if (tmp)
		out = ft_substr(out, tmp - out + 1, ft_strlen(tmp));
	if (!out)
		return (NULL);
	return (out);
}
