/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:07 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/31 12:37:47 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H
# include "env.h"
# include "libft.h"
# include <fcntl.h>

# define MSHRC ".mshrc"

// config.c
int		parseconfig(void);

// config_utils.c
size_t	cfg_varcount(char *line);
void	cfg_err(size_t lnbr, char *msg);
int		cfg_matchkw(char *line);

#endif
