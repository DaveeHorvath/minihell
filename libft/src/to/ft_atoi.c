/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:50:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 02:35:55 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi.c
 */

#include "lft_to.h"

/** @brief Converts s to a 64-bit integer value
 *
 * @param *s String to convert
 * @retval int64_t Converted value of s
 */
int64_t	ft_atoi64(const char *s)
{
	return (ft_atoi_base(s, DECIMAL));
}

/** @brief Converts s to a 32-bit integer value
 *
 * @param *s String to convert
 * @retval int32_t Converted value of s
 */
int32_t	ft_atoi32(const char *s)
{
	int64_t	out;

	out = ft_atoi64(s);
	if (out > INT32_MAX)
		return (-1);
	if (out < INT32_MIN)
		return (0);
	return ((int32_t)out);
}

/**	@brief Converts s to a 16-bit integer value
 *
 * @param *s String to convert
 * @retval int16_t Converted value of s
 */
int16_t	ft_atoi16(const char *s)
{
	int64_t	out;

	out = ft_atoi64(s);
	if (out > INT16_MAX)
		return (-1);
	if (out < INT16_MIN)
		return (0);
	return ((int16_t)out);
}

/**	@brief Converts s to an 8-bit integer value
 *
 * @param *s String to convert
 * @retval int8_t Converted value of s
 */
int8_t	ft_atoi8(const char *s)
{
	int64_t	out;

	out = ft_atoi64(s);
	if (out > INT8_MAX)
		return (-1);
	if (out < INT8_MIN)
		return (0);
	return ((int8_t)out);
}

/** @brief Alias for ft_atoi32
 */
int	ft_atoi(const char *s)
{
	return (ft_atoi32(s));
}
