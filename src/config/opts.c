/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:02:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/07 15:15:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "errcodes.h"

static void	getrcfile(size_t argc, char **argv, t_msh_opts *opts, size_t *i);

t_msh_opts	msh_parseopts(size_t argc, char **argv)
{
	t_msh_opts	opts;
	size_t		i;

	i = 1;
	ft_bzero(&opts, sizeof(t_msh_opts));
	while (i < argc)
	{
		if (ft_strequals(argv[i], "--rcfile")
			|| ft_strequals(argv[i], "--init-file"))
			getrcfile(argc, argv, &opts, &i);
		else if (ft_strequals(argv[i], "--norc"))
			opts.norc = 1;
		i++;
	}
	return (opts);
}

static void	getrcfile(size_t argc, char **argv, t_msh_opts *opts, size_t *i)
{
	if (++(*i) == argc)
	{
		ft_dprintf(2, "msh: %s: option requires an argument\n",
			ft_strtrim(argv[*i - 1], "-"));
		ft_exit(E_ARGS);
	}
	opts->cfg_fname = ft_push(ft_strdup(argv[*i]));
}
