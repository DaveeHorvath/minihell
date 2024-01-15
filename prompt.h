/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:25:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/06 18:56:34 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H
# include "libft.h"

// Misc sequences
# define RESET "\e[0m"
# define BOLD "\e[1m"
# define ULINE "\e[4m"

// Foreground colors
# define FG0 "\e[30m"
# define FG1 "\e[31m"
# define FG2 "\e[32m"
# define FG3 "\e[33m"
# define FG4 "\e[34m"
# define FG5 "\e[35m"
# define FG6 "\e[36m"
# define FG7 "\e[37m"

// Background colors
# define BG0 "\e[40m"
# define BG1 "\e[41m"
# define BG2 "\e[42m"
# define BG3 "\e[43m"
# define BG4 "\e[44m"
# define BG5 "\e[45m"
# define BG6 "\e[46m"
# define BG7 "\e[47m"

#endif
