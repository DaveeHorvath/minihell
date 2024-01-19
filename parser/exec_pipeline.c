/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:47:57 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/19 15:48:20 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	char			*content;
	struct s_cmd	*next;
}	t_list;

int	exec_pipeline(char *s)
{
	t_list	*commands;
	int		prev_out;

	commands = make_commands(s);
	while (commands)
	{
		if (commands->next)
		{
			get_fds(commands->content, &prev_out);
		}
		commands = commands->next;
	}
}

int	skip_til(char *s, char c)
{
	int	i;

	while (s[i] && s[i] != c)
		i++;
	return (i);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}

void	ft_lstaddback(t_list **list, t_list *new)
{
	if (!*list)
	{
		*list = new;
		return ;
	}
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = new;
}

int	append(t_list **cmds, char *s, int old_i, int i)
{
	t_list	*new;
	char	*cont;

	cont = ft_substr(s, old_i, i - old_i);
	if (!cont)
		return (0);
	new = ft_lstnew(cont);
	if (!new)
	{
		free(cont);
		return (0);
	}
	ft_lstaddback(cmds, new);
	return (1);
}

t_list	*make_commands(char *s)
{
	t_list	*commands;
	int		i;
	int		old_i;

	i = 0;
	old_i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			i += skip_til(&s[i], s[i]);
			if (!s[i])
				return (0);
		}
		else if (s[i] == '|')
		{
			if (!append(&commands, s, old_i, i))
				return (clean());
			old_i = i + 1;
		}
		i++;
	}
	return (commands);
}
