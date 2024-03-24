/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:07 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/07 15:27:28 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H
# include "env.h"
# include "alias.h"
# include "libft.h"
# include <fcntl.h>

# define MSHRC ".mshrc"
# define DEFAULTPROMPT "%B%U%F3%n%K5%F0@%F6%K3%m %u%F4%K7put%Uchar %u>%R "

typedef struct s_msh_opts
{
	const char	*cfg_fname;
	uint8_t		norc;
}	t_msh_opts;

// opts.c
t_msh_opts	msh_parseopts(size_t argc, char **argv);

// config.c
int			msh_parseconfig(const char *cfg_fname);

// config_utils.c
size_t		cfg_varcount(char *line);
void		cfg_err(size_t lnbr, char *msg);
int			cfg_matchkw(char *line);

#endif
