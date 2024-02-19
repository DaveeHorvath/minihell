/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:59:46 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:16 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_calloc.c
 */

#include "libft.h"

/** @brief Allocates a new block and zero initializes it
 *
 * @param count Amount of objects to allocate
 * @param size Size of the objects to allocate
 * @retval void * Pointer to the newly allocated block
 * or NULL if the allocation failed
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*out;
	size_t	asize;

	asize = count * size;
	if (asize < count && asize < size)
		return (NULL);
	out = ft_alloc(count * size);
	if (!out)
		return (NULL);
	ft_bzero(out, count * size);
	return (out);
}
