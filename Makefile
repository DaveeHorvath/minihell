# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 14:15:21 by ivalimak          #+#    #+#              #
#    Updated: 2024/03/25 10:25:00 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

BUILD	=	normal

CC				=	cc
cflags.common	=	-Wall -Wextra -Werror -D RL_HFNAME='".msh_history"'
cflags.debug	=	-g
cflags.debugm	=	$(cflags.debug) -D DEBUG_MSG=1
cflags.asan		=	$(cflags.debug) -fsanitize=address
cflags.normal	=	
CFLAGS			=	$(cflags.common) $(cflags.$(BUILD))

SRCDIR	=	src
OBJDIR	=	obj
INCDIR	=	inc
LIBDIR	=	libft
LIBFT	=	$(LIBDIR)/libft.a

READLINEDIR	=	readline
BUILTINDIR	=	builtins
CONFIGDIR	=	config
ENVDIR		=	env
PARSERDIR	=	parser
PROMPTDIR	=	prompt

READLINEFILES	=	ft_readline.c \
					ft_rl_altcmd.c \
					ft_rl_command.c \
					ft_rl_completion.c \
					ft_rl_completionutils.c \
					ft_rl_ctrlcmd.c \
					ft_rl_cursor.c \
					ft_rl_history.c \
					ft_rl_historyfile.c \
					ft_rl_historyutils.c \
					ft_rl_increment.c \
					ft_rl_input.c \
					ft_rl_inpututils.c \
					ft_rl_match.c \
					ft_rl_matchutils.c \
					ft_rl_replace.c \
					ft_rl_search.c \
					ft_rl_searchutils.c \
					ft_rl_termutils.c \
					ft_rl_utils.c \
					ft_rl_wildcard.c

BUILTINFILES	=	cd.c \
					echo.c \
					env.c \
					exit.c \
					export.c \
					pwd.c \
					unset.c

CONFIGFILES		=	opts.c \
					config.c \
					config_utils.c

ENVFILES		=	env.c \
					env_utils.c

PARSERFILES		=	command_split.c \
					errors.c \
					exec_builtins.c \
					expand_token.c \
					files.c \
					handle_tokens.c \
					pipeline.c \
					run.c \
					single_command_parser.c \
					tree.c \
					utils.c \
					validation.c \
					signalhandler.c

PROMPTFILES		=	color.c \
					prompt.c

FILES	=	main.c \
			utils.c \
			$(addprefix $(READLINEDIR)/, $(READLINEFILES)) \
			$(addprefix $(BUILTINDIR)/, $(BUILTINFILES)) \
			$(addprefix $(CONFIGDIR)/, $(CONFIGFILES)) \
			$(addprefix $(ENVDIR)/, $(ENVFILES)) \
			$(addprefix $(PARSERDIR)/, $(PARSERFILES)) \
			$(addprefix $(PROMPTDIR)/, $(PROMPTFILES))

SRCS	=	$(addprefix $(SRCDIR)/, $(FILES))
OBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJDIR) $(LIBFT) $(OBJS)
	@echo Compiling $(NAME)...
	@$(CC) $(CFLAGS) -I$(INCDIR) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)

$(OBJDIR):
	@echo Creating objdir...
	@mkdir -p $(OBJDIR)/$(READLINEDIR)
	@mkdir -p $(OBJDIR)/$(BUILTINDIR)
	@mkdir -p $(OBJDIR)/$(CONFIGDIR)
	@mkdir -p $(OBJDIR)/$(ENVDIR)
	@mkdir -p $(OBJDIR)/$(PARSERDIR)
	@mkdir -p $(OBJDIR)/$(PROMPTDIR)

$(LIBFT):
	@make --no-print-directory -C $(LIBDIR) BUILD=$(BUILD)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(READLINEDIR)/%.o: $(SRCDIR)/$(READLINEDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(BUILTINDIR)/%.o: $(SRCDIR)/$(BUILTINDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(CONFIGDIR)/%.o: $(SRCDIR)/$(CONFIGDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(ENVDIR)/%.o: $(SRCDIR)/$(ENVDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(PARSERDIR)/%.o: $(SRCDIR)/$(PARSERDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(PROMPTDIR)/%.o: $(SRCDIR)/$(PROMPTDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@make --no-print-directory -C $(LIBDIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make --no-print-directory -C $(LIBDIR) fclean
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all
