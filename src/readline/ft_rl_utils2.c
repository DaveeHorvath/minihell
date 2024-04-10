/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:24:22 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/10 13:17:50 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rl_internal.h"

static inline void	insertword(t_rl_input *input, t_rl_word *word);

t_rl_input	*ft_rl_strinput(const char *s)
{
	t_rl_input	*out;
	size_t		start;
	size_t		end;

	out = ft_push(ft_alloc(sizeof(*out)));
	if (!out)
		return (NULL);
	*out = (t_rl_input){.plen = 0, .prompt = NULL, .cursor = NULL,
		.exittype = ACL, .head = NULL, .current = NULL};
	start = 0;
	while (s[start])
	{
		end = start;
		while (s[end] && !ft_isspace(s[end]))
			end++;
		insertword(out, ft_rl_strword(ft_substr(s, start, end - start)));
		start = end;
		while (s[end] && ft_isspace(s[end]))
			end++;
		insertword(out, ft_rl_strword(ft_substr(s, start, end - start)));
		if (s[start])
			start++;
	}
	return (out);
}

t_rl_word	*ft_rl_strword(const char *s)
{
	t_rl_word	*out;

	if (!s || !*s)
		return (NULL);
	ft_push((void *)s);
	out = ft_push(ft_alloc(sizeof(*out)));
	if (!out)
		return (NULL);
	*out = (t_rl_word){.len = ft_strlen(s), .word = (char *)s, .wtype = NORMAL,
		.next = NULL, .prev = NULL};
	out->i = out->len;
	if (*s == ' ')
		out->wtype = SPACE;
	return (out);
}

uint8_t		ft_rl_isdir(const char *path)
{
	struct stat	file;

	stat(path, &file);
	return (file.st_mode & S_IFDIR);
}

void	ft_rl_updateinput(t_rl_input *input, t_rl_input *newinput)
{
	ft_rl_popwords(input->head);
	input->head = ft_rl_dupwords(newinput->head);
	input->current = input->head;
	ft_rl_redisplay(input, LINE);
}

static inline void	insertword(t_rl_input *input, t_rl_word *word)
{
	if (!word)
		return ;
	if (!input->current)
	{
		input->head = word;
		input->current = input->head;
	}
	else
	{
		word->prev = input->current;
		input->current->next = word;
		input->current = word;
	}
}
