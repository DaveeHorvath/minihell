/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:49:48 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 07:15:50 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_DATA_H
# define LFT_DATA_H
# include <stdlib.h>
# include <stdint.h>

typedef enum e_base
{
	BINARY,
	OCTAL,
	DECIMAL,
	HEX
}	t_base;

typedef struct s_list
{
	void			*blk;
	size_t			*size;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_hmap_pair
{
	const char	*key;
	void		*value;
}	t_hmap_pair;

typedef struct s_hmap
{
	size_t		size;
	size_t		bsize;
	size_t		count;
	t_hmap_pair	**items;
}	t_hmap;

typedef struct s_obj
{
	size_t			marks;
	size_t			traps;
	size_t			blksize;
	size_t			asize;
	const void		*blk;
	struct s_obj	*next;
}	t_obj;

typedef struct s_stack
{
	const void		*blk;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_vm
{
	uint8_t	ptrap;
	t_stack	*stack;
	size_t	maxobjs;
	size_t	objs;
	t_obj	*head;
}	t_vm;

#endif
