CC = gcc
CFLAG = -Wall -Wextra -Werror -g
SRC = main3.c extract_ft.c get_time.c get_rights.c get_data.c \
path_builder.c print_lf.c tool_list.c max_width.c sort.c \
print_ls.c  sort_ft.c print.c tool_data.c check_opt.c \
ft_ls.c split_arg.c
SRC_DIR = ./src
SRC_C = $(patsubst %, $(SRC_DIR)/%, $(SRC))
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_DIR = ./obj
OBJ_O = $(patsubst %, $(OBJ_DIR)/%, $(OBJ))
HDIR = include
LDIR = libft
LIB = ft
FILE =
NAME = ft_ls
.PHONY: re run rr clean fclean all $(NAME)

all: libft.a $(NAME)

libft.a:
	@make re -C ./libft

$(NAME): $(OBJ_O)
	@$(CC) -o $@ -I $(HDIR) -l $(LIB) -L $(LDIR) $(OBJ_O) $(CFLAG)
	@echo "\033[32mft_ls done\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@ -I $(HDIR) $(CFLAG)

clean:
	@rm -rf $(OBJ_O)
	@echo "\033[31mobject files removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mft_ls removed\033[0m"

re: fclean all

run:
	@./$(NAME) $(FILE) | cat -e

rr: re run
