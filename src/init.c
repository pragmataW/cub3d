#include "cub3d.h"
#include <stdlib.h>
#include <stdio.h>
#include "../mlx/mlx.h"

t_game *init(t_map *map)
{ 
    t_game *game;
    int x;
    game = malloc(sizeof(t_game) * 1);
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cum3d");
    game->no = malloc(sizeof(t_img) * 1);
    game->so = malloc(sizeof(t_img) * 1);
    game->we = malloc(sizeof(t_img) * 1);
    game->ea = malloc(sizeof(t_img) * 1);
    game->full_img = malloc(sizeof(t_img) * 1);
    game->full_img->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->no->img = mlx_xpm_file_to_image(game->mlx, map->north, &x, &x);
    game->so->img = mlx_xpm_file_to_image(game->mlx, map->south, &x, &x);
    game->we->img = mlx_xpm_file_to_image(game->mlx, map->west, &x, &x);
    game->ea->img = mlx_xpm_file_to_image(game->mlx, map->east, &x, &x);
    if (!game->no->img || !game->so->img || !game->we->img || !game->ea->img)
        exit(printf("Error\nWrong texture path\n"));
    game->no->addr = (int *)mlx_get_data_addr(game->no->img, &x, &x, &x);
    game->so->addr = (int *)mlx_get_data_addr(game->so->img, &x, &x, &x);
    game->we->addr = (int *)mlx_get_data_addr(game->we->img, &x, &x, &x);
    game->ea->addr = (int *)mlx_get_data_addr(game->ea->img, &x, &x, &x);
    game->floor = map->floor_val;
    game->ceil = map->ceil_val;
    return (game);
}