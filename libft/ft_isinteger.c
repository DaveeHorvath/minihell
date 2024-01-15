/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:32:59 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/08 17:48:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isinteger.c
 */

#include "libft.h"

/** @brief Checks if the string n is an integer in text form
 *
 * @param *n String to check
 * @retval int 1 if *s is an integer, 0 if not
 */
int	ft_isinteger(char *n)
{
	size_t	i;
	long	nbr;

	if (ft_strlen(n) > 10 + (*n == '-'))
		return (0);
	i = 0;
	if (*n == '+' || *n == '-')
		i++;
	if (!n[i])
		return (0);
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
			return (0);
		i++;
	}
	nbr = ft_atol(n);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}
