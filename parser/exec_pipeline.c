/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:47:57 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/20 20:13:34 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

char	*ft_substr(char *s, int start, int len);

typedef struct s_cmd
{
	int				fd[2];
	char			**argv;
	char			**env;
	pid_t			pid;
	struct s_cmd	*next;
}	t_cmd;


typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;


void *clean(void)
{
	return (0);
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
	t_list *current;

	current = *list;
	if (!*list)
	{
		*list = new;
		return ;
	}
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = new;
	*list = current;
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

t_list	*parse_pipeline(char *s)
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
	if (!append(&commands, s, old_i, i))
		return (clean());
	return (commands);
}

void child_error(void)
{
	clean();
	printf("something went stupid\n");
	exit(-1);
}

void command_not_found(void)
{
	clean();
	printf("no such command stupid\n");
	exit(-1);
}

pid_t	call_cmd(t_cmd *cmd, int *fds)
{
	pid_t	pid;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
		if (dup2(1, fds[1]) == -1 || dup2(0, fds[0]) == -1)
			child_error();
		path = get_path(cmd->argv[0]);
		if (!path)
			cmd_not_found();
		execve(path, &(cmd->argv[1]), cmd->env);
	}
	else if (pid != -1)
		return (pid);
	else
		child_error();
}

// pipex getpath from path
char *get_path(char *cmd)
{
	return ("/bin/ls");
}

// split the list on isspace, disreagrd the redirection 
// and/or the next ones as well
char **get_arguments(char *toparse)
{
	return (NULL);
}

void	make_cmd(t_list *toparse, t_cmd *commands, int *fds)
{
	extern char	**environ;

	commands->argv = get_arguments(toparse);
	commands->env = environ;
	commands->pid = call_cmd(commands, fds);
}

// split the string on isspace, for <, >> and > open the correct fd
// if it fails give an error
// check for heredocs to take, if yes read it to a temp file
// and then at the end unlink
void parse_fds(char *to_parse, int fds[2])
{
	return;
}

void	get_fds(t_list *toparse, int *prev_out, int *fds)
{
	int		pipefds[2];

	fds[0] = -1;
	fds[1] = -1;
	parse_fds(toparse->content, fds);
	if (toparse->next)
	{
		if (pipe(pipefds) == -1)
			return ;
	}
	if (fds[0] == -1)
		fds[0] = *prev_out;
	if (fds[1] == -1)
	{
		*prev_out = pipefds[0];
		fds[1] = pipefds[1];
	}
}

int	exec_pipeline(char *s)
{
	t_list	*commands;
	t_cmd	*to_exec;
	int		prev_out;
	int		exitcode;
	int		fds[2];

	commands = parse_pipeline(s);
	prev_out = -1;
	while (commands)
	{
		get_fds(commands, &prev_out, (int *)fds);
		make_cmd(commands, to_exec, (int *)fds);
		commands = commands->next;
	}
	while (to_exec)
	{
		waitpid(to_exec, &exitcode, WNOHANG);
		if (!to_exec->next && WIFEXITED(exitcode))
		{
			clean();
			return (exitcode);
		}
		to_exec = to_exec->next;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	exec_pipeline(argv[1]);
}
