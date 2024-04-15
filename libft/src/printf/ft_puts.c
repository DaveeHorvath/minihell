/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:30:19 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 00:41:56 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_puts.c
 */

#include "libft.h"

static int	putleft(char *s, int nchars, int *flags);
static int	putright(char *s, int nchars, int *flags);

/** @brief Prints a string according to the flags
 *
 * @param args va_list containing the string to be printed
 * @param *flags Pointer to the output flag array
 * @retval int Amount of characters written or -1 if an error occurred
 */
int	ft_puts(va_list args, int *flags)
{
	const char	nullstr[7] = "(null)\0";
	char		*s;
	int			nchars;
	int			slen;

	s = va_arg(args, char *);
	if (!s)
		s = (char *)nullstr;
	slen = (int)ft_strlen(s);
	if (flags[3] == 0)
		nchars = 0;
	else if (flags[3] > 0 && flags[3] <= slen)
		nchars = flags[3];
	else
		nchars = slen;
	if (nchars == 0 && flags[2] == 0)
		return (0);
	if (flags[0] == 1)
		return (putleft(s, nchars, flags));
	return (putright(s, nchars, flags));
}

static int	putleft(char *s, int nchars, int *flags)
{
	int	ret;
	int	out;

	out = 0;
	ret = 0;
	while (out < nchars && ret >= 0)
	{
		ret = ft_putchar_fd(s[out], ft_pfgetfd());
		out += ret;
	}
	if (ret < 0)
		return (-1);
	ret = putpadding(flags[2] - nchars, ' ', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	return (out);
}

static int	putright(char *s, int nchars, int *flags)
{
	int	ret;
	int	out;
	int	i;

	i = 0;
	out = 0;
	ret = putpadding(flags[2] - nchars, ' ', &flags[0], flags);
	out += ret;
	while (i < nchars && ret >= 0)
	{
		ret = ft_putchar_fd(s[i++], ft_pfgetfd());
		out += ret;
	}
	if (ret < 0)
		return (-1);
	return (out);
}
