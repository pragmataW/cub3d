/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:10:13 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/08 03:56:20 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <stdio.h>
#include "../mlx/mlx.h"

static void	init_texture(t_game *g)
{
	g->tex.line_h = 0;
	g->tex.step = 0.0;
	g->tex.text_pos = 0.0;
	g->tex.draw_start = 0;
	g->tex.draw_end = 0;
	g->tex.tex_x = 0;
	g->tex.tex_y = 0;
	g->tex.text_w = TEXTURE_W;
	g->tex.text_h = TEXTURE_H;
}

void	init_t_map(t_map *map)
{
	map->map = NULL;
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->floor = NULL;
	map->ceil = NULL;
}

static void	init_ray(t_game *g)
{
	g->ray.pos_x = 0.0;
	g->ray.pos_y = 0.0;
	g->ray.dir_x = 0.0;
	g->ray.dir_y = 0.0;
	g->ray.camera_x = 0.0;
	g->ray.raydir_x = 0.0;
	g->ray.raydir_y = 0.0;
	g->ray.deltadist_x = 0.0;
	g->ray.deltadist_y = 0.0;
	g->ray.sidedist_x = 0.0;
	g->ray.sidedist_y = 0.0;
	g->ray.step_x = 0;
	g->ray.step_y = 0;
	g->ray.plane_x = 0.0;
	g->ray.plane_y = 0.0;
	g->ray.map_x = 0;
	g->ray.map_y = 0;
	g->ray.is_hit = 0;
	g->ray.side = 0;
	g->ray.perp_wall_dist = 0.0;
	g->ray.wall_x = 0.0;
}

static t_game	*init2(t_game *game, t_map *map)
{
	int	x;

	if (!game->no->img || !game->so->img || !game->we->img || !game->ea->img)
		exit(printf("Error\nWrong texture path\n"));
	game->no->addr = (int *)mlx_get_data_addr(game->no->img, &x, &x, &x);
	game->so->addr = (int *)mlx_get_data_addr(game->so->img, &x, &x, &x);
	game->we->addr = (int *)mlx_get_data_addr(game->we->img, &x, &x, &x);
	game->ea->addr = (int *)mlx_get_data_addr(game->ea->img, &x, &x, &x);
	if (!game->no->addr || !game->so->addr
		|| !game->we->addr || !game->ea->addr)
		exit(printf("Error\nWrong texture path\n"));
	game->w = 0;
	game->a = 0;
	game->s = 0;
	game->d = 0;
	game->l = 0;
	game->r = 0;
	game->floor = map->floor_val;
	game->ceil = map->ceil_val;
	game->speed = 0.03f;
	game->rot_speed = 0.02f;
	init_texture(game);
	init_ray(game);
	game->map = map;
	return (game);
}

t_game	*init(t_map *map)
{
	t_game	*game;
	int		x;

	game = malloc(sizeof(t_game) * 1);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
	game->no = malloc(sizeof(t_img) * 1);
	game->so = malloc(sizeof(t_img) * 1);
	game->we = malloc(sizeof(t_img) * 1);
	game->ea = malloc(sizeof(t_img) * 1);
	game->full_img = malloc(sizeof(t_img) * 1);
	game->full_img->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->full_img->addr = (int *)mlx_get_data_addr(game->full_img->img, &x,
			&x, &x);
	game->no->img = mlx_xpm_file_to_image(game->mlx, map->north, &x, &x);
	game->so->img = mlx_xpm_file_to_image(game->mlx, map->south, &x, &x);
	game->we->img = mlx_xpm_file_to_image(game->mlx, map->west, &x, &x);
	game->ea->img = mlx_xpm_file_to_image(game->mlx, map->east, &x, &x);
	init2(game, map);
	return (game);
}
