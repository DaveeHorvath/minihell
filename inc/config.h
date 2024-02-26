/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:07 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/20 15:29:32 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H
# include "env.h"
# include "libft.h"
# include <fcntl.h>

# define MSHRC ".mshrc"
//# define DEFAULTPROMPT "%B%U%F3%n%K1%F0@%F1%K0%K7%m %u%F1%K4putchar >%R "
# define DEFAULTPROMPT "%B%F6%n%F1@%F4%m%f%b %F5%1D%f %B%F1$%R "

// config.c
int		parseconfig(void);

// config_utils.c
size_t	cfg_varcount(char *line);
void	cfg_err(size_t lnbr, char *msg);
int		cfg_matchkw(char *line);

#endif
