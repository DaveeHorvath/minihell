/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:06:00 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/15 14:12:10 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int	main(void)
{
	const char	*ps = "%B%f6USER%f1@%f4HOST%R %f5CURDIR%R %B%f1$%R ";

	prompt(ps);
}
