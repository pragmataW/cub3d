#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "src/cub3d.h"
#include "../mlx/mlx.h"

int main(int argc, char **argv)
{
    t_map *map;
    t_game *game;

    if (argc < 1)
        exit(printf("Wrong argument count\n"));
    else
    {
        map = malloc(sizeof(t_map) * 1);
        parse_map(map, argv[1]);
        char_control(map->map);
        is_passed(map->map);
        game = init(map);
        mlx_loop(game->mlx);
    }
}