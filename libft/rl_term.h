/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:48:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/10 20:00:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RL_TERML_H
# define RL_TERML_H
# include "libft.h"
# include "rl_data.h"

// misc
# define TERM_STATUS "\e[6n"

// clear
# define TERM_CLEAR_END "\e[0J"
# define TERM_CLEAR_START "\e[1J"
# define TERM_CLEAR_SCREEN "\e[2J"
# define TERM_CLEAR_BUFFER "\e[3J"

// ft_rl_cursor.c
void	ft_rl_shiftcursor(t_rl_input *input, size_t n, char direction);
void	ft_rl_movecursor(t_rl_input *input, size_t n, char direction);
void	ft_rl_resetscreen(t_rl_input *input);

// ft_rl_termutils.c
void	ft_rl_term_cur_updatepos(size_t promptlen);
void	ft_rl_term_cur_inputstart(void);
void	ft_rl_term_cur_getpos(int *row, int *col, char update);
void	ft_rl_term_cur_setpos(int row, int col);

#endif
