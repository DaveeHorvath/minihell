/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:30:47 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/11 16:33:14 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline t_rl_input	**getinput(void);

t_rl_input	*ft_rl_getcurinput(void)
{
	return (*getinput());
}

void	ft_rl_setcurinput(const t_rl_input *input)
{
	*getinput() = (t_rl_input *)input;
}

static inline t_rl_input	**getinput(void)
{
	static t_rl_input	*input = NULL;

	return (&input);
}
