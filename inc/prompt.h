/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:25:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/19 22:58:03 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H
# include "env.h"
# include "libft.h"
# include "rl_term.h"

char	*prompt(const char *p);
char	*chcolor(const char *code, const char type, char **out);

#endif
