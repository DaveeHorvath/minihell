/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:37:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 06:18:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_MATH_H
# define LFT_MATH_H
# include "lft_data.h"
# include "lft_limits.h"

/*   no alloc   */
/**   int   **/
int64_t		ft_pow(const int64_t n, int64_t p);
int64_t		ft_max(const int64_t a, const int64_t b);
int64_t		ft_min(const int64_t a, const int64_t b);
/**   int   **/

/**   uint   **/
uint64_t	ft_upow(const uint64_t n, int64_t p);
uint64_t	ft_umax(const uint64_t a, const uint64_t b);
uint64_t	ft_umin(const uint64_t a, const uint64_t b);
/**   uint   **/

/**   double   **/
double		ft_sqrt(const double n);
double		ft_ceil(const double n);
double		ft_round(const double n);
double		ft_floor(const double n);
/**   double   **/
/*   no alloc   */

#endif
