/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:25:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/16 16:52:26 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H
# include "libft.h"

// Misc sequences
# define RESET "\e[0m"
# define BOLD "\e[1m"
# define BOLDR "\e[22m"
# define ULINE "\e[4m"
# define ULINER "\e[24m"

// Foreground colors
# define FG0 "\e[30m"
# define FG1 "\e[31m"
# define FG2 "\e[32m"
# define FG3 "\e[33m"
# define FG4 "\e[34m"
# define FG5 "\e[35m"
# define FG6 "\e[36m"
# define FG7 "\e[37m"
# define FGR "\e[39m"

// Background colors
# define BG0 "\e[40m"
# define BG1 "\e[41m"
# define BG2 "\e[42m"
# define BG3 "\e[43m"
# define BG4 "\e[44m"
# define BG5 "\e[45m"
# define BG6 "\e[46m"
# define BG7 "\e[47m"
# define BGR "\e[49m"

void	prompt(const char *p);
char	*chcolor(const char *code, const char type);

#endif
