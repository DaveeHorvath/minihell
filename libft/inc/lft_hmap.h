/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_hmap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:07:12 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 19:51:49 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_HMAP_H
# define LFT_HMAP_H
# include "lft_data.h"
# include "lft_limits.h"

# define HMAP_DEL ((void *)0x1)

/*   alloc   */
uint8_t	ft_mapadd(t_hmap *hmap, const char *key, const void *val);

t_hmap	*ft_mapnew(void);
/*   alloc   */

/*   no alloc   */
uint8_t	ft_maprm(t_hmap *hmap, const char *key);

void	*ft_mapget(t_hmap *hmap, const char *key);

void	ft_mappop(t_hmap_pair *pair);
void	ft_mappop_all(t_hmap *hmap);
/*   no alloc   */

#endif
