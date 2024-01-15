/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:43:06 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/31 07:45:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_return.c
 */

#include "libft.h"

/** @brief Frees all memory before returning
 *
 * @param rval Return value
 * @retval int rval
 */
int	ft_return(int rval)
{
	ft_popall();
	ft_clean();
	return (rval);
}
