/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:55:20 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 13:28:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putd.c
 */

#include "libft.h"

static int	putleft(int n, int ndigits, int *flags);
static int	putright(int n, int ndigits, int *flags);
static int	getlen(int n, int *ndigits, int *flags);

/** @brief Prints an int according to the flags
 *
 * @param args va_list containing the int to be printed
 * @param *flags Pointer to the output flag array
 * @retval int Amount of characters printed or -1 if an error occurred
 */
int	ft_putd(va_list args, int *flags)
{
	int	n;
	int	ndigits;

	if (flags[3] > 0)
	{
		flags[1] = 0;
		ndigits = flags[3];
	}
	else
		ndigits = 0;
	n = va_arg(args, int);
	if (n < 0)
		ndigits++;
	if (flags[0] == 1)
		return (putleft(n, ndigits, flags));
	if (flags[5] > 0)
		if (flags[2] > 0 && flags[3] > 0)
			ndigits++;
	return (putright(n, ndigits, flags));
}

static int	putleft(int n, int ndigits, int *flags)
{
	int	nlen;
	int	ret;
	int	out;

	out = 0;
	nlen = getlen(n, &ndigits, flags);
	ret = putpadding(ndigits - nlen, '0', &n, flags);
	out += ret;
	if (ret < 0)
		return (-1);
	if (flags[3] != 0 || n != 0)
	{
		ret = ft_putnbr_fd(n, ft_pfgetfd(), flags);
		out += ret;
	}
	if (ret < 0)
		return (-1);
	if (n == INT_MIN)
		n = INT_MAX;
	else if (n < 0)
		n = -n;
	ret = putpadding(flags[2] - out, ' ', &n, flags);
	if (ret < 0)
		return (-1);
	return (out + ret);
}

static int	putright(int n, int ndigits, int *flags)
{
	int	nlen;
	int	ret;
	int	out;

	out = 0;
	nlen = getlen(n, &ndigits, flags);
	if (flags[1] == 1)
		ret = putpadding(flags[2] - nlen, '0', &n, flags);
	else
		ret = putpadding(flags[2] - ndigits, ' ', &n, flags);
	out += ret;
	if (ret < 0)
		return (-1);
	if (flags[1] == 0)
	{
		ret = putpadding(ndigits - nlen, '0', &n, flags);
		out += ret;
	}
	if (ret >= 0)
		ret = 0;
	if ((flags[3] != 0 || n != 0) && ret == 0)
		ret = ft_putnbr_fd(n, ft_pfgetfd(), flags);
	if (ret < 0)
		return (-1);
	return (out + ret);
}

static int	getlen(int n, int *ndigits, int *flags)
{
	int	digits;

	digits = ft_intlen(n, DECIMAL);
	if (flags[1] == 1 && flags[5] > 0 && n == 0)
		digits++;
	if (flags[0] == 1 && n < 0 && digits > *ndigits)
		digits--;
	if (flags[5] > 0 && flags[1] == 1 && n <= 0)
		digits--;
	if (flags[0] == 0 && flags[5] > 0 && (flags[3] != 0 || n != 0))
		digits++;
	else if (flags[5] > 0 && flags[2] == 0 && flags[0] == 1
		&& digits <= *ndigits)
		digits++;
	if (flags[0] == 0 && flags[2] > 0 && digits > *ndigits)
		if (flags[3] != 0 || n != 0)
			*ndigits = digits;
	if (flags[0] == 1 && flags[2] > 0 && digits > *ndigits
		&& flags[5] > 0)
		*ndigits = digits;
	if (flags[5] > 0 && digits > *ndigits && flags[2] == 0)
		digits = *ndigits + 1;
	else if (flags[5] > 0 && digits > *ndigits)
		*ndigits = digits;
	return (digits);
}
