/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:41:00 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 12:02:25 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file
 */

#include "libft.h"

/** @brief Checks if is an alphabetical character
 *
 * @param c Character to check
 * @retval int 1 if c is alphabetical, 0 if not
 */
int	ft_isalpha(int c)
{
	if (ft_isupper(c) > 0 || ft_islower(c) > 0)
		return (1);
	return (0);
}
