/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:23:51 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/16 16:54:34 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*chcolor(const char *code, const char type)
{
	const static char	fg[8][6] = {FG0, FG1, FG2, FG3, FG4, FG5, FG6, FG7};
	const static char	bg[8][6] = {BG0, BG1, BG2, BG3, BG4, BG5, BG6, BG7};

	if (type == 'F')
		ft_printf("%s", fg[*code - '0']);
	else if (type == 'K')
		ft_printf("%s", bg[*code - '0']);
	else if (type == 'B')
		ft_printf("%s", BOLD);
	else if (type == 'U')
		ft_printf("%s", ULINE);
	else if (type == 'f')
		ft_printf("%s", FGR);
	else if (type == 'k')
		ft_printf("%s", BGR);
	else if (type == 'b')
		ft_printf("%s", BOLDR);
	else if (type == 'u')
		ft_printf("%s", ULINER);
	if (type == 'F' || type == 'K')
		code++;
	return ((char *)code);
}
