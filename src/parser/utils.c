/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:56:37 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/20 13:56:54 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_filename(char *s, int start)
{
	int	i;

	i = start;
	while (s[i] == ' ')
		i++;
	return (ft_push(ft_strdup(&s[i])));
}
