/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:23:51 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/19 23:11:11 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*chcolor(const char *code, const char type, char **out)
{
	const static char	fg[8][6] = {SGR_FG0, SGR_FG1, SGR_FG2, SGR_FG3,
		SGR_FG4, SGR_FG5, SGR_FG6, SGR_FG7};
	const static char	bg[8][6] = {SGR_BG0, SGR_BG1, SGR_BG2, SGR_BG3,
		SGR_BG4, SGR_BG5, SGR_BG6, SGR_BG7};

	if (type == 'F')
		*out = ft_strjoin(*out, fg[*code - '0']);
	else if (type == 'K')
		*out = ft_strjoin(*out, bg[*code - '0']);
	else if (type == 'B')
		*out = ft_strjoin(*out, SGR_BOLDON);
	else if (type == 'U')
		*out = ft_strjoin(*out, SGR_ULINEON);
	else if (type == 'f')
		*out = ft_strjoin(*out, SGR_FGR);
	else if (type == 'k')
		*out = ft_strjoin(*out, SGR_BGR);
	else if (type == 'b')
		*out = ft_strjoin(*out, SGR_BOLDOFF);
	else if (type == 'u')
		*out = ft_strjoin(*out, SGR_ULINEOFF);
	if (type == 'F' || type == 'K')
		code++;
	return ((char *)code);
}
