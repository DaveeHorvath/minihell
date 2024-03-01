/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:32 by dhorvath          #+#    #+#             */
/*   Updated: 2024/02/29 15:37:33 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>

void	new_interrupt(int sig)
{
	printf("\n got signal %i \n", sig);
}

int	main(void)
{
	signal(2, new_interrupt);
	while (1)
		;
}
