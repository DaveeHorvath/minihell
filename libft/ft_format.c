/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:06:23 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 11:43:34 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_format.c
 */

#include "libft.h"

static char	*parseformat(const char *f, int *flags, va_list args);
static char	*getflags(const char *f, int *flags);
static void	parseflag(const char c, int *flags);
static int	getvalue(const char *f, va_list args);

/** @brief Parses the format to print
 *
 * Parses the format specifier and any flags and runs the
 * corresponding printing function
 * @param **f Address of the pointer to the current position in the format string
 * @param args va_list containing the variable to print
 * @retval int Amount of characters printed or -1 if an error occurred
 */
int	ft_putarg(const char **f, va_list args)
{
	int	flags[6];

	*f = parseformat(*f, flags, args);
	if (**f == '%')
		return (ft_putc(args, flags, '%'));
	if (**f == 'c')
		return (ft_putc(args, flags, 'c'));
	if (**f == 'd' || **f == 'i')
		return (ft_putd(args, flags));
	if (**f == 'u')
		return (ft_putu(args, flags));
	if (**f == 's')
		return (ft_puts(args, flags));
	if (**f == 'x' || **f == 'X')
		return (ft_putx(args, flags, **f));
	if (**f == 'p')
		return (ft_putp(args, flags));
	*f = *f - 1;
	return (0);
}

/** @brief Parses any flags from the format specifier
 *
 * @param *f Pointer to the start of the format specifier
 * @param *flags Pointer to the flag array
 * @param args va_list potentially containing flag variable values
 * @retval char * Pointer to the format specifier without the preceding flags
 */
static char	*parseformat(const char *f, int *flags, va_list args)
{
	flags[0] = 0;
	flags[1] = 0;
	flags[4] = 0;
	flags[5] = 0;
	f = getflags(f, flags);
	flags[2] = getvalue(f, args);
	while (ft_isdigit(*f) == 1 || *f == '*')
		f++;
	flags[3] = -1;
	if (*f == '.')
	{
		f++;
		flags[1] = 0;
		flags[3] = getvalue(f, args);
		while (ft_isdigit(*f) == 1 || *f == '*')
			f++;
	}
	return ((char *)f);
}

static char	*getflags(const char *f, int *flags)
{
	while (ft_contains("# +-0", *f) == 1)
	{
		parseflag(*f, flags);
		f++;
	}
	return ((char *)f);
}

static void	parseflag(const char c, int *flags)
{
	if (c == '-')
		flags[0] = 1;
	else if (c == '0' && flags[0] == 0)
		flags[1] = 1;
	else if (c == '#')
		flags[4] = 1;
	else if (c == '+')
		flags[5] = 1;
	else if (c == ' ' && flags[5] == 0)
		flags[5] = 2;
}

static int	getvalue(const char *f, va_list args)
{
	if (*f == '*')
		return (va_arg(args, int));
	if (ft_isdigit(*f) > 0)
		return (ft_atoi(f));
	return (0);
}
