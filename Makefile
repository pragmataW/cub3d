NAME = cub3d

SRC = main.c src/check_map_utils.c src/check_map.c src/utils.c src/file_extension_check.c \
      src/get_colors.c src/parse_map.c src/read_map.c src/init.c

FLAGS = gcc -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	make -C mlx
	cp ./mlx/libmlx.a .
	cp ./libft/libft.a .
	$(FLAGS) $(SRC) -o $(NAME) ./libmlx.a ./libft.a -lXext -lX11 -lm 

clean: 
	$(RM) $(NAME)

fclean: clean
	make fclean -C libft
	make clean -C mlx
	$(RM) libft.a libmlx.a

re: fclean all

.PHONY: clean fclean all re
