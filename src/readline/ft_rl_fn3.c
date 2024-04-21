/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_fn3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:56:41 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/18 14:07:33 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

uint8_t	ft_rl_nxh(t_rl_input *input)
{
	t_rl_input	*newinput;

	if (!input)
		return (1);
	newinput = ft_rl_hist_getnext(input, 1);
	if (!newinput || input == newinput)
		return (1);
	ft_rl_updateinput(input, newinput);
	while (input->current && input->current->next)
		input->current = input->current->next;
	ft_rl_redisplay(input, LINE);
	return (1);
}

uint8_t	ft_rl_soh(t_rl_input *input)
{
	t_rl_input	*newinput;
	t_rl_input	*tmp;

	if (!input)
		return (1);
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
	ft_rl_updateinput(input, newinput);
	while (input->current && input->current->next)
		input->current = input->current->next;
	ft_rl_redisplay(input, LINE);
	return (1);
}

uint8_t	ft_rl_eoh(t_rl_input *input)
{
	t_rl_input	*newinput;
	t_rl_input	*tmp;

	if (!input)
		return (1);
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
	ft_rl_updateinput(input, newinput);
	while (input->current && input->current->next)
		input->current = input->current->next;
	ft_rl_redisplay(input, LINE);
	return (1);
}

uint8_t	ft_rl_rsh(t_rl_input *input)
{
	uint64_t	key;

	if (!input)
		return (1);
	ft_rl_eol(input);
	key = ft_rl_hist_search(input, KEY_UP);
	if (input->sigexit)
		return (0);
	if (ft_rl_getmap(key) != ft_rl_rsh)
		return (ft_rl_execmap(input, key));
	return (1);
}

uint8_t	ft_rl_fsh(t_rl_input *input)
{
	uint64_t	key;

	if (!input)
		return (1);
	ft_rl_eol(input);
	key = ft_rl_hist_search(input, KEY_DOWN);
	if (input->sigexit)
		return (0);
	if (ft_rl_getmap(key) != ft_rl_fsh)
		return (ft_rl_execmap(input, key));
	return (1);
}
