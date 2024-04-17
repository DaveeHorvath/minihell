/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:09:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/17 17:33:40 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

void	ft_rl_heredoc_hook(t_rl_input *input)
{
	input->sigexit = 1;
	input->exittype = EOFF;
	ft_putstr_fd(TERM_STATUS, 1);
}
