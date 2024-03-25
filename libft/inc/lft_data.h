/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:49:48 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/24 19:30:24 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_DATA_H
# define LFT_DATA_H
# include <stdlib.h>
# include <stdint.h>

typedef struct s_list
{
	void			*blk;
	size_t			*size;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_obj
{
	uint8_t			marked;
	size_t			blksize;
	size_t			asize;
	void			*blk;
	struct s_obj	*next;
}	t_obj;

typedef struct s_stack
{
	void			*blk;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_vm
{
	t_stack	*stack;
	size_t	maxobjs;
	size_t	objs;
	t_obj	*head;
}	t_vm;

typedef enum e_base
{
	BINARY,
	OCTAL,
	DECIMAL,
	HEX
}	t_base;

#endif
