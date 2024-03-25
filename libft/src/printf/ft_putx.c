/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:09:20 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 13:29:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putx.c
 */

#include "libft.h"

static int	getlen(unsigned long n, int *ndigits, int *flags);
static int	putleft(unsigned long n, int ndigits, int *flags, int upper);
static int	putright(unsigned long n, int ndigits, int *flags, int upper);

/** @brief Prints an unsigned integer as a hex value according to the flags
 *
 * @param args va_list containing the unsigned integer to be printed
 * @param *flags Pointer to the flag array
 * @param format Character specifying whether to print a-f as lowercase (x)
 * or uppercase (X) characters
 * @retval int Amount of characters printed or -1 if an error occurred
 */
int	ft_putx(va_list args, int *flags, char format)
{
	unsigned int	n;
	int				ndigits;
	int				upper;

	upper = 0;
	if (flags[3] > 0)
		ndigits = flags[3];
	else
		ndigits = 0;
	n = va_arg(args, unsigned long);
	if (format == 'X')
		upper = 1;
	if (upper == 1 && flags[4] == 1)
		flags[4] = 2;
	if (n == 0)
		flags[4] = 0;
	if (flags[0] == 1)
		return (putleft(n, ndigits, flags, upper));
	return (putright(n, ndigits, flags, upper));
}

static int	putleft(unsigned long n, int ndigits, int *flags, int upper)
{
	int	nlen;
	int	ret;
	int	out;

	out = 0;
	nlen = getlen(n, &ndigits, flags);
	ret = putpadding(ndigits - nlen, '0', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	if (flags[3] != 0 || n != 0)
	{
		ret = ft_putxnbr_fd(n, ft_pfgetfd(), upper);
		out += ret;
	}
	if (ret < 0)
		return (-1);
	ret = putpadding(flags[2] - out, ' ', &flags[0], flags);
	if (ret < 0)
		return (-1);
	return (out + ret);
}

static int	putright(unsigned long n, int ndigits, int *flags, int upper)
{
	int	nlen;
	int	ret;
	int	out;

	out = 0;
	nlen = getlen(n, &ndigits, flags);
	if (flags[1] == 1)
		ret = putpadding(flags[2] - ndigits, '0', &flags[0], flags);
	else
		ret = putpadding(flags[2] - ndigits, ' ', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = putpadding(ndigits - nlen, '0', &flags[0], flags);
	out += ret;
	if (ret >= 0)
		ret = 0;
	if ((flags[3] != 0 || n != 0) && ret == 0)
		ret = ft_putxnbr_fd(n, ft_pfgetfd(), upper);
	if (ret < 0)
		return (-1);
	return (out + ret);
}

static int	getlen(unsigned long n, int *ndigits, int *flags)
{
	int	digits;

	digits = ft_uintlen(n, HEX);
	if (flags[2] > *ndigits && flags[4] > 0)
		digits += 2;
	if (flags[2] > *ndigits && flags[4] > 0 && n != 0)
		*ndigits += 2;
	if (flags[0] == 0 && flags[2] > 0 && digits > *ndigits)
		if (flags[3] != 0 || n > 0)
			*ndigits = digits;
	return (digits);
}
