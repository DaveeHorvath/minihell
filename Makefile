# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 14:15:21 by ivalimak          #+#    #+#              #
#    Updated: 2024/02/26 17:47:42 by dhorvath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

BUILD	=	normal

CC				=	cc
cflags.common	=	-Wall -Wextra -Werror
cflags.debug	=	-g
cflags.debugm	=	$(cflags.debug) -D DEBUG_MSG=1
cflags.asan		=	$(cflags.debug) -fsanitize=address -static-libsan
cflags.normal	=	
CFLAGS			=	$(cflags.common) $(cflags.$(BUILD))

SRCDIR	=	src
OBJDIR	=	obj
INCDIR	=	inc
LIBDIR	=	libft
LIBFT	=	$(LIBDIR)/libft.a

BUILTINDIR	=	builtins
CONFIGDIR	=	config
ENVDIR		=	env
PARSERDIR	=	parser
PROMPTDIR	=	prompt

BUILTINFILES	=	$(BUILTINDIR)/cd.c \
					$(BUILTINDIR)/echo.c \
					$(BUILTINDIR)/env.c \
					$(BUILTINDIR)/exit.c \
					$(BUILTINDIR)/export.c \
					$(BUILTINDIR)/pwd.c \
					$(BUILTINDIR)/unset.c

CONFIGFILES		=	$(CONFIGDIR)/config.c \
					$(CONFIGDIR)/config_utils.c

ENVFILES		=	$(ENVDIR)/env.c \
					$(ENVDIR)/env_utils.c

PARSERFILES		=	$(PARSERDIR)/errors.c \
					$(PARSERDIR)/expand_token.c \
					$(PARSERDIR)/handle_tokens.c \
					$(PARSERDIR)/pipeline.c \
					$(PARSERDIR)/run.c \
					$(PARSERDIR)/single_command_parser.c \
					$(PARSERDIR)/tree.c \
					$(PARSERDIR)/utils.c \
					$(PARSERDIR)/files.c \
					$(PARSERDIR)/exec_builtins.c

PROMPTFILES		=	$(PROMPTDIR)/color.c \
					$(PROMPTDIR)/prompt.c

FILES	=	main.c \
			$(BUILTINFILES) \
			$(CONFIGFILES) \
			$(ENVFILES) \
			$(PARSERFILES) \
			$(PROMPTFILES)

SRCS	=	$(addprefix $(SRCDIR)/, $(FILES))
OBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJDIR) $(LIBFT) $(OBJS)
	@echo Compiling $(NAME)...
	@$(CC) $(CFLAGS) -I$(INCDIR) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)

$(OBJDIR):
	@echo Creating objdir...
	@mkdir -p $(OBJDIR)/$(BUILTINDIR)
	@mkdir -p $(OBJDIR)/$(CONFIGDIR)
	@mkdir -p $(OBJDIR)/$(ENVDIR)
	@mkdir -p $(OBJDIR)/$(PARSERDIR)
	@mkdir -p $(OBJDIR)/$(PROMPTDIR)

$(LIBFT):
	@make -C $(LIBDIR) BUILD=$(BUILD)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
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
	@make -C $(LIBDIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBDIR) fclean
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all
