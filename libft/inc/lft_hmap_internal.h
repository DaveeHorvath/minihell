/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_hmap_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:59:46 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 20:26:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_HMAP_INTERNAL_H
# define LFT_HMAP_INTERNAL_H
# include "lft_hmap.h"

# define HMAP_SALT_1 347ULL
# define HMAP_SALT_2 677ULL

# define HMAP_DEF_SIZE 23ULL

/*   alloc   */
uint8_t		resizemap(t_hmap *hmap, size_t bsize);
uint8_t		shrinkmap(t_hmap *hmap);
uint8_t		growmap(t_hmap *hmap);

t_hmap		*ft_mapnew_size(size_t size);
/*   alloc   */

/*   no alloc   */
uint64_t	getnextprime(uint64_t n);

size_t		gethash(const char *s, const size_t size, const size_t attempt);
/*   no alloc   */

#endif
