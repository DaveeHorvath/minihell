# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 14:15:21 by ivalimak          #+#    #+#              #
#    Updated: 2024/02/17 19:44:11 by dhorvath         ###   ########.fr        #
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

SRCDIR	=	parser
OBJDIR	=	obj
LIBDIR	=	libft
LIBFT	=	$(LIBDIR)/libft.a

FILES	=	test.c \
			expand_token.c \
			handle_tokens.c \
			single_command_parser.c \
			pipeline.c \
			errors.c \
			tree.c \
			run.c

SRCS	=	$(addprefix $(SRCDIR)/, $(FILES))
OBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(OBJDIR) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo Compiling $(NAME)...
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@make -C $(LIBDIR) BUILD=$(BUILD)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBDIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBDIR) fclean
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all
