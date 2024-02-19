/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:51:46 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 19:44:48 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RL_DATA_H
# define RL_DATA_H
# include "libft.h"

typedef struct s_rl_input
{
	size_t		i;
	size_t		promptlen;
	size_t		inputlen;
	const char	*prompt;
	char		*input;
}	t_rl_input;

typedef struct s_rl_termstate
{
	int	t_rows;
	int	t_cols;
	int	t_row;
	int	t_col;
	int	i_row;
	int	i_col;
}	t_rl_termstate;

#endif
