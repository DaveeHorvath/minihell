/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_fn3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:56:41 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/29 00:36:04 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

uint8_t	ft_rl_nxh(t_rl_input *input)
{
	t_rl_input	*newinput;

	newinput = ft_rl_hist_getnext(input, 1);
	if (!newinput || input == newinput)
		return (1);
	ft_rl_popwords(input->head);
	input->head = ft_rl_dupwords(newinput->head);
	input->current = input->head;
	while (input->current && input->current->next)
		input->current = input->current->next;
	ft_rl_redisplay(input, LINE);
	return (1);
}

uint8_t	ft_rl_soh(t_rl_input *input)
{
	t_rl_input	*newinput;
	t_rl_input	*tmp;

	newinput = ft_rl_hist_getprev(input, 1);
	if (!newinput || input == newinput)
		return (1);
	tmp = newinput;
	newinput = ft_rl_hist_getprev(newinput, 0);
	while (newinput != tmp)
	{
		tmp = newinput;
		newinput = ft_rl_hist_getprev(newinput, 0);
	}
	ft_rl_popwords(input->head);
	input->head = ft_rl_dupwords(newinput->head);
	input->current = input->head;
	while (input->current && input->current->next)
		input->current = input->current->next;
	ft_rl_redisplay(input, LINE);
	return (1);
}

uint8_t	ft_rl_eoh(t_rl_input *input)
{
	t_rl_input	*newinput;
	t_rl_input	*tmp;

	newinput = ft_rl_hist_getnext(input, 1);
	if (!newinput || input == newinput)
		return (1);
	tmp = newinput;
	newinput = ft_rl_hist_getnext(newinput, 0);
	while (newinput != tmp)
	{
		tmp = newinput;
		newinput = ft_rl_hist_getnext(newinput, 0);
	}
	ft_rl_popwords(input->head);
	input->head = ft_rl_dupwords(newinput->head);
	input->current = input->head;
	while (input->current && input->current->next)
		input->current = input->current->next;
	ft_rl_redisplay(input, LINE);
	return (1);
}
