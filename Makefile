# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 14:15:21 by ivalimak          #+#    #+#              #
#    Updated: 2024/04/15 15:39:12 by dhorvath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

BUILD	=	normal

CC				=	cc
cflags.common	=	-Wall -Wextra -Werror -D RL_HFNAME=\".msh_history\"
cflags.debug	=	-g
cflags.debugm	=	$(cflags.debug) -D DEBUG_MSG=1
cflags.rldebug	=	$(cflags.debug) -D RL_DEBUG_MSG=1
cflags.asan		=	$(cflags.rldebug) -fsanitize=address
cflags.normal	=	-Ofast
cflags.extra	=	
CFLAGS			=	$(cflags.common) $(cflags.$(BUILD)) $(cflags.extra)

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
					ft_rl_color.c \
					ft_rl_complete.c \
					ft_rl_complete2.c \
					ft_rl_complete3.c \
					ft_rl_complete_utils.c \
					ft_rl_cursor.c \
					ft_rl_debug_utils.c \
					ft_rl_exec.c \
					ft_rl_fn.c \
					ft_rl_fn2.c \
					ft_rl_fn3.c \
					ft_rl_fn4.c \
					ft_rl_fn5.c \
					ft_rl_history.c \
					ft_rl_history_file.c \
					ft_rl_history_search.c \
					ft_rl_history_utils.c \
					ft_rl_history_utils2.c \
					ft_rl_init.c \
					ft_rl_initfuncs.c \
					ft_rl_initkeys.c \
					ft_rl_input.c \
					ft_rl_input_utils.c \
					ft_rl_keymap.c \
					ft_rl_keymap_lists.c \
					ft_rl_keymap_utils.c \
					ft_rl_remove.c \
					ft_rl_signal.c \
					ft_rl_term_utils.c \
					ft_rl_utils.c \
					ft_rl_utils2.c \
					ft_rl_utils3.c \
					ft_rl_wildcard.c \
					ft_rl_wildcard_utils.c \
					ft_rl_word.c \
					ft_rl_word_replace.c

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

TESTFILES		=	$(subst main.c, tester.c, $(FILES))
TEST_SRC		=	$(addprefix $(SRCDIR)/, $(TESTFILES))
TESTOBJS		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(TEST_SRC))

SRCS	=	$(addprefix $(SRCDIR)/, $(FILES))
OBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJDIR) $(LIBFT) $(OBJS)
	@echo Compiling $(NAME)...
	@$(CC) $(CFLAGS) -I$(INCDIR) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)

tester: $(OBJDIR) $(LIBFT) $(TESTOBJS)
	@echo $(TESTOBJS)
	@echo Compiling tests...
	@$(CC) $(CFLAGS) -I$(INCDIR) $(TESTOBJS) -L$(LIBDIR) -lft -o tester
	@echo "running tester"
	@./tester test.txt
	@rm tester

$(OBJDIR):
	@echo Creating objdir...
	@mkdir -p $(OBJDIR)/$(READLINEDIR)
	@mkdir -p $(OBJDIR)/$(BUILTINDIR)
	@mkdir -p $(OBJDIR)/$(CONFIGDIR)
	@mkdir -p $(OBJDIR)/$(ENVDIR)
	@mkdir -p $(OBJDIR)/$(PARSERDIR)
	@mkdir -p $(OBJDIR)/$(PROMPTDIR)

$(LIBFT):
	@make --no-print-directory -C $(LIBDIR) BUILD=$(BUILD) cflags.extra=$(cflags.extra)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/$(INCDIR) -c $< -o $@

$(OBJDIR)/$(READLINEDIR)/%.o: $(SRCDIR)/$(READLINEDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/$(INCDIR) -c $< -o $@

$(OBJDIR)/$(BUILTINDIR)/%.o: $(SRCDIR)/$(BUILTINDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/$(INCDIR) -c $< -o $@

$(OBJDIR)/$(CONFIGDIR)/%.o: $(SRCDIR)/$(CONFIGDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/$(INCDIR) -c $< -o $@

$(OBJDIR)/$(ENVDIR)/%.o: $(SRCDIR)/$(ENVDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/$(INCDIR) -c $< -o $@

$(OBJDIR)/$(PARSERDIR)/%.o: $(SRCDIR)/$(PARSERDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/$(INCDIR) -c $< -o $@

$(OBJDIR)/$(PROMPTDIR)/%.o: $(SRCDIR)/$(PROMPTDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/$(INCDIR) -c $< -o $@

clean:
	@make --no-print-directory -C $(LIBDIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make --no-print-directory -C $(LIBDIR) fclean
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all
