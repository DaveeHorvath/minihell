NAME=minishell

MAIN=src/main.c
MAIN_OBJ=obj/main.o
SRC_DIR=src/
SRC=$(addprefix $(SRC_DIR), parser.c)
LIBFT_DIR=libft_p/
LIBFT=$(LIBFT_DIR)libft.a
OBJ_DIR=obj/
OBJ=$(addprefix $(OBJ_DIR), $(notdir $(SRC)))
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I include/ -I libft_p/includes
CC=cc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ) $(MAIN_OBJ)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) $(MAIN_OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C bonus $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all