/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:28:17 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/16 18:32:08 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *s)
{
	free(s);
}

int	is_command_separator(char *s)
{
	if (ft_strncmp(s, "|", 1))
		return (1);
	if (ft_strncmp(s, "&&", 2) || ft_strncmp(s, "||", 2))
		return (2);
	return (0);
}

t_list	*parse_into_commands(char *s)
{
	int		i;
	int		old_i;
	t_list	*list;
	t_list	*new;
	char	*tmp;

	i = 0;
	old_i = 0;
	while (s[i])
	{
		if (s[i]=='\"' || s[i]=='\'')
		{
			tmp = ft_strchr(&s[i], s[i]);
			if (!tmp)
			{
				ft_lstclear(&list, &del);
				return (0);
			}
			i += tmp - &s[i];
		}
		if (is_command_separator(&s[i]) || !s[i])
		{
			tmp = ft_substr(s, old_i, i - old_i);
			if (!tmp)
			{
				ft_lstclear(&list, &del);
				return (0);
			}
			new = ft_lstnew(tmp);
			if (!new)
			{
				free(tmp);
				ft_lstclear(&list, &del);
				return (0);
			}
			ft_lstadd_back(&list, new);
			if (s[i])
			{
				tmp = ft_substr(s, i, is_command_separator(&s[i]));
				if (!tmp)
				{
					ft_lstclear(&list, &del);
					return (0);
				}
				new = ft_lstnew(tmp);
				if (!new)
				{
					free(tmp);
					ft_lstclear(&list, &del);
					return (0);
				}
				ft_lstadd_back(&list, new);
			}
			i += is_command_separator(&s[i]);
			old_i = i;
		}
	}
}

t_list	*parse_into_exec(t_list *list)
{
	t_list	*commands;
	t_list	*redirects;
	char *to_split;
	int i;
	int old_i;
	while (list)
	{
		to_split = list->content;
		i = 0;
		old_i = 0;
		while (to_split[i])
		{
			if (to_split[i] == '<' || to_split[i] == '>')
			{
				old_i = i;
				i++;
				if (to_split[i] == to_split[i - 1])
					i++;
				while (to_split[i] == ' ')
					i++;
				while (to_split[i] && to_split[i] != ' ')
					i++;
				ft_lstadd_back(&redirects, ft_lstnew(ft_substr(to_split, old_i, i)));
				old_i = i;
			}
			else if (to_split[i] == '\'' || to_split[i] == '\"')
			{
				char c;
				old_i = i;
				c = to_split[i];
				i++;
				while (to_split[i] && to_split[i] != c)
					i++;
				ft_lstadd_back(&commands, ft_lstnew(ft_substr(to_split, old_i, i)));
				old_i = i;
			}
			else if (to_split[i] == ' ')
			{
				ft_lstadd_back(&commands, ft_lstnew(ft_substr(to_split, old_i, i - 1)));
				while (to_split[i] == ' ')
					i++;
				old_i = i;
			}
			else
				i++;
		}
		list = list->next;
	}
}
