# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 14:15:21 by ivalimak          #+#    #+#              #
#    Updated: 2024/01/16 14:57:47 by dhorvath         ###   ########.fr        #
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

LIBDIR	=	libft
LIBFT	=	$(LIBDIR)/libft.a

SRCS	=	main.c \
			prompt.c

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo Compiling $(NAME)...
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)

$(LIBFT):
	@make -C $(LIBDIR) BUILD=$(BUILD)

%.o: %.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBDIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBDIR) fclean
	@rm -f $(NAME)

re: fclean all

re: fclean all