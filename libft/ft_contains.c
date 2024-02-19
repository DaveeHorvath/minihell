/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:33:41 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:55:16 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_contains.c
 */

/** @brief Check if s contains c
 *
 * Goes through the string s, checking if any of the characters in s are c
 * @param *s Pointer to the string to look for c in
 * @param c Character to look for in s
 * @retval int 0 if c is not found, 1 if c is found
 */
int	ft_contains(const char *s, char c)
{
	while (*s)
	{
		if (*s++ == c)
			return (1);
	}
	return (0);
}
