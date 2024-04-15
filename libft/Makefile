# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 15:26:18 by ivalimak          #+#    #+#              #
#    Updated: 2024/04/13 12:07:56 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

BUILD	=	normal

CC				=	cc
cflags.common	=	-Wall -Wextra -Werror
cflags.debug	=	-g
cflags.debugm 	=	$(cflags.debug) -D DEBUG_MSG=1
cflags.asan		=	$(cflags.debug) -fsanitize=address
cflags.normal	=	-Ofast
cflags.extra	=	
CFLAGS			=	$(cflags.common) $(cflags.$(BUILD)) $(cflags.extra)

SRCDIR	=	src
OBJDIR	=	obj
INCDIR	=	inc

GCDIR	=	gc
GNLDIR	=	gnl
ISDIR	=	is
LSTDIR	=	lst
MEMDIR	=	mem
NBRDIR	=	nbr
PFDIR	=	printf
PUTDIR	=	put
STRDIR	=	str
TODIR	=	to

GCFILES		=	ft_alloc.c \
				ft_arrdup.c \
				ft_calloc.c \
				ft_clean.c \
				ft_exit.c \
				ft_getblksize.c \
				ft_mark.c \
				ft_obj.c \
				ft_pop.c \
				ft_push.c \
				ft_pushtrap.c \
				ft_return.c \
				ft_stack.c \
				ft_sweep.c \
				ft_vm.c

GNLFILES	=	gnl.c \
				gnl_utils.c

ISFILES		=	ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isint_base.c \
				ft_isint.c \
				ft_isint_utils.c \
				ft_islower.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_isuint_base.c \
				ft_isuint.c \
				ft_isupper.c

LSTFILES	=	ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstdup.c \
				ft_lstfirst.c \
				ft_lstlast.c \
				ft_lstnew.c \
				ft_lstpopall.c \
				ft_lstpop.c \
				ft_lstpushall.c \
				ft_lstpush.c \
				ft_lstrmnode.c

MEMFILES	=	ft_bzero.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c

NBRFILES	=	ft_intlen.c \
				ft_uintlen.c

PFFILES		=	ft_dprintf.c \
				ft_format.c \
				ft_printf.c \
				ft_putc.c \
				ft_putd.c \
				ft_putp.c \
				ft_puts.c \
				ft_putu.c \
				ft_putx.c \
				printf_utils.c

PUTFILES	=	ft_debugmsg.c \
				ft_debugnbr.c \
				ft_debugunbr.c \
				ft_debugxnbr.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putunbr_fd.c \
				ft_putxnbr_fd.c

STRFILES	=	ft_split.c \
				ft_strchr.c \
				ft_strclen.c \
				ft_strdup.c \
				ft_strequals.c \
				ft_strjoin.c \
				ft_strnjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strlower.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strremove.c \
				ft_strrev.c \
				ft_strsjoin.c \
				ft_strsnjoin.c \
				ft_strtrim.c \
				ft_strupper.c \
				ft_substr.c \
				ft_wordcount.c

TOFILES		=	ft_atoi_base.c \
				ft_atoi.c \
				ft_atou_base.c \
				ft_atou.c \
				ft_itoa_base.c \
				ft_itoa.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_utoa_base.c \
				ft_utoa.c

FILES	=	$(addprefix $(GCDIR)/, $(GCFILES)) \
			$(addprefix $(GNLDIR)/, $(GNLFILES)) \
			$(addprefix $(ISDIR)/, $(ISFILES)) \
			$(addprefix $(LSTDIR)/, $(LSTFILES)) \
			$(addprefix $(MEMDIR)/, $(MEMFILES)) \
			$(addprefix $(NBRDIR)/, $(NBRFILES)) \
			$(addprefix $(PFDIR)/, $(PFFILES)) \
			$(addprefix $(PUTDIR)/, $(PUTFILES)) \
			$(addprefix $(STRDIR)/, $(STRFILES)) \
			$(addprefix $(TODIR)/, $(TOFILES))

SRCS	=	$(addprefix $(SRCDIR)/, $(FILES))
OBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@printf "\e[34;1mLIBFT >\e[m Creating %s\n" $@
	@ar -crs $(NAME) $(OBJS)
	@printf "\e[34;1mLIBFT >\e[m \e[1mDone!\e[m\n"

$(OBJDIR):
	@printf "\e[34;1mLIBFT >\e[m Creating objdirs\n" $@
	@mkdir -p $(OBJDIR)/$(GCDIR)
	@mkdir -p $(OBJDIR)/$(GNLDIR)
	@mkdir -p $(OBJDIR)/$(ISDIR)
	@mkdir -p $(OBJDIR)/$(LSTDIR)
	@mkdir -p $(OBJDIR)/$(MEMDIR)
	@mkdir -p $(OBJDIR)/$(NBRDIR)
	@mkdir -p $(OBJDIR)/$(PFDIR)
	@mkdir -p $(OBJDIR)/$(PUTDIR)
	@mkdir -p $(OBJDIR)/$(STRDIR)
	@mkdir -p $(OBJDIR)/$(TODIR)

$(OBJDIR)/$(GCDIR)/%.o: $(SRCDIR)/$(GCDIR)/%.c
	@printf "\e[34;1mLIBFT >\e[m Compiling %s\n" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(GNLDIR)/%.o: $(SRCDIR)/$(GNLDIR)/%.c
	@printf "\e[34;1mLIBFT >\e[m Compiling %s\n" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(ISDIR)/%.o: $(SRCDIR)/$(ISDIR)/%.c
	@printf "\e[34;1mLIBFT >\e[m Compiling %s\n" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(LSTDIR)/%.o: $(SRCDIR)/$(LSTDIR)/%.c
	@printf "\e[34;1mLIBFT >\e[m Compiling %s\n" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(MEMDIR)/%.o: $(SRCDIR)/$(MEMDIR)/%.c
	@printf "\e[34;1mLIBFT >\e[m Compiling %s\n" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(NBRDIR)/%.o: $(SRCDIR)/$(NBRDIR)/%.c
	@printf "\e[34;1mLIBFT >\e[m Compiling %s\n" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(PFDIR)/%.o: $(SRCDIR)/$(PFDIR)/%.c
	@printf "\e[34;1mLIBFT >\e[m Compiling %s\n" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(PUTDIR)/%.o: $(SRCDIR)/$(PUTDIR)/%.c
	@printf "\e[34;1mLIBFT >\e[m Compiling %s\n" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(STRDIR)/%.o: $(SRCDIR)/$(STRDIR)/%.c
	@printf "\e[34;1mLIBFT >\e[m Compiling %s\n" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/$(TODIR)/%.o: $(SRCDIR)/$(TODIR)/%.c
	@printf "\e[34;1mLIBFT >\e[m Compiling %s\n" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all
