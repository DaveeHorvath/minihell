/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:56:37 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/26 14:13:52 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_filename(char *s, int start)
{
	int	i;

	i = start;
	while (s[i] == ' ')
		i++;
	return (ft_push(ft_strdup(&s[i])));
}
