/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termctrl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:48:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/31 23:27:43 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCTRL_H
# define TERMCTRL_H

// clear
# define TERM_CLEAR_END "\e[0J"
# define TERM_CLEAR_START "\e[1J"
# define TERM_CLEAR_SCREEN "\e[2J"
# define TERM_CLEAR_BUFFER "\e[3J"

// movement
# define TERM_CUR_LEFT "\e[D"
# define TERM_CUR_RIGHT "\e[C"
# define TERM_CUR_RESET "\e[1;1H"

#endif
