NAME = xox
SRC = src/main.c src/board.c src/game.c src/checker.c src/minimax.c src/pixel_put.c src/utils.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C mlx
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lmlx -framework OpenGL -framework AppKit -Lmlx

clean:
	@make clean -C mlx
	@rm -f $(OBJ)

fclean: clean
	@make clean -C mlx
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re