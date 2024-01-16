/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:06:00 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/16 23:22:50 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int	main(int argc, char **argv)
{
	const char	*ps = "%B%F6%n%F1@%F4%m%f%b %F5%6~%f %B%F1$%R ";

	prompt(ps);
	if (argc > 1)
	{
		ft_printf("echo %s\n", argv[1]);
		msh_echo(argv[1], 1);
		prompt(ps);
		ft_printf("echo -n %s\n", argv[1]);
		msh_echo(argv[1], 0);
	}
	return (0);
}
