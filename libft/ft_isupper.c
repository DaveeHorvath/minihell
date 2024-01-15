/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:57:12 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 12:55:34 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isupper.c
 */

/** @brief Checks if c is an uppercase character
 *
 * @param c Character to check
 * @retval int 1 if c is uppercase, 0 if not
 */
int	ft_isupper(int c)
{
	if (c >= 'A' || c <= 'Z')
		return (1);
	return (0);
}
