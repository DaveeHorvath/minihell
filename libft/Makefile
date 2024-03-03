# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 15:26:18 by ivalimak          #+#    #+#              #
#    Updated: 2024/03/02 09:37:23 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

BUILD	=	normal

CC				=	cc
cflags.common	=	-Wall -Wextra -Werror
cflags.debug	=	-g
cflags.debugm 	=	$(cflags.debug) -D DEBUG_MSG=1
cflags.asan		=	$(cflags.debug) -fsanitize=address
cflags.normal	=	
CFLAGS			=	$(cflags.common) $(cflags.$(BUILD))

SRCS	=	ft_atoi.c \
			ft_atol.c \
			ft_free.c \
			ft_bzero.c \
			ft_alloc.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isupper.c \
			ft_islower.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_isinteger.c \
			ft_basename.c \
			ft_contains.c \
			ft_itoa.c \
			ft_uitoa.c \
			ft_intlen.c \
			ft_uintlen.c \
			ft_hexlen.c \
			ft_memset.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_putnbr_fd.c \
			ft_putunbr_fd.c \
			ft_putxnbr_fd.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_splitstrs.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_wordcount.c \
			ft_strremove.c \
			ft_strequals.c \
			ft_strupper.c \
			ft_strlower.c \
			ft_strsjoin.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strclen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_strrev.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstnew.c \
			ft_lstdup.c \
			ft_lstpop.c \
			ft_lstpush.c \
			ft_lstlast.c \
			ft_lstrmnode.c \
			ft_lstpopall.c \
			ft_lstpushall.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_dprintf.c \
			ft_printf.c \
			ft_format.c \
			ft_putc.c \
			ft_putd.c \
			ft_putp.c \
			ft_puts.c \
			ft_putu.c \
			ft_putx.c \
			printf_utils.c \
			get_next_line.c \
			gnl_utils.c \
			ft_debugxnbr.c \
			ft_debugunbr.c \
			ft_debugnbr.c \
			ft_debugmsg.c \
			ft_getblksize.c \
			ft_return.c \
			ft_clean.c \
			ft_sweep.c \
			ft_mark.c \
			ft_exit.c \
			ft_push.c \
			ft_pop.c \
			ft_obj.c \
			ft_vm.c \

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@echo Creating libft...
	@ar -crs $(NAME) $(OBJS)

%.o: %.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
