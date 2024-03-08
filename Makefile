NAME = cub3D

SRC = main.c src/char_checker.c src/check_map_utils.c src/check_map.c src/direction.c src/draw.c src/file_extension_check.c \
	src/get_colors.c src/init.c src/key.c src/parse_map_utils.c src/parse_map.c src/ray_cast.c src/read_map.c src/utils.c

FLAGS = cc -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	make -C mlx
	cp ./mlx/libmlx.a .
	cp ./libft/libft.a .
	$(FLAGS) $(SRC) -o $(NAME) ./libmlx.a ./libft.a -framework OpenGL -framework AppKit

clean: 
	$(RM) $(NAME)

fclean: clean
	make fclean -C libft
	make clean -C mlx
	$(RM) libft.a libmlx.a

re: fclean all

.PHONY: clean fclean all re
