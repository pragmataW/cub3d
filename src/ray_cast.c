/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:10:04 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/08 12:37:12 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../mlx/mlx.h"
#include <math.h>

static void	get_deltadist(t_game *g, int x)
{
	g->ray.camera_x = 2 * x / (double)WIDTH - 1;
	g->ray.raydir_x = g->ray.dir_x + g->ray.plane_x * g->ray.camera_x;
	g->ray.raydir_y = g->ray.dir_y + g->ray.plane_y * g->ray.camera_x;
	g->ray.map_x = (int)g->ray.pos_x;
	g->ray.map_y = (int)g->ray.pos_y;
	if (g->ray.raydir_y == 0)
		g->ray.deltadist_y = 1e30;
	else
		g->ray.deltadist_y = fabs(1 / g->ray.raydir_y);
	if (g->ray.raydir_x == 0)
		g->ray.deltadist_x = 1e30;
	else
		g->ray.deltadist_x = fabs(1 / g->ray.raydir_x);
}

static void	get_sidedist(t_game *g)
{
	if (g->ray.raydir_x < 0)
	{
		g->ray.step_x = -1;
		g->ray.sidedist_x = (g->ray.pos_x - g->ray.map_x) * g->ray.deltadist_x;
	}
	else
	{
		g->ray.step_x = 1;
		g->ray.sidedist_x
			= (g->ray.map_x + 1.0 - g->ray.pos_x) * g->ray.deltadist_x;
	}
	if (g->ray.raydir_y < 0)
	{
		g->ray.step_y = -1;
		g->ray.sidedist_y = (g->ray.pos_y - g->ray.map_y) * g->ray.deltadist_y;
	}
	else
	{
		g->ray.step_y = 1;
		g->ray.sidedist_y
			= (g->ray.map_y + 1.0 - g->ray.pos_y) * g->ray.deltadist_y;
	}
}

static void	dda(t_game *g, t_map *map)
{
	g->ray.is_hit = 0;
	while (g->ray.is_hit == 0)
	{
		if (g->ray.sidedist_x < g->ray.sidedist_y)
		{
			g->ray.sidedist_x += g->ray.deltadist_x;
			g->ray.map_x += g->ray.step_x;
			g->ray.side = 0;
		}
		else
		{
			g->ray.sidedist_y += g->ray.deltadist_y;
			g->ray.map_y += g->ray.step_y;
			g->ray.side = 1;
		}
		if (map->map[g->ray.map_y][g->ray.map_x] == '1')
			g->ray.is_hit = 1;
	}
	if (g->ray.side == 0)
		g->ray.perp_wall_dist = g->ray.sidedist_x - g->ray.deltadist_x;
	else
		g->ray.perp_wall_dist = g->ray.sidedist_y - g->ray.deltadist_y;
	g->tex.line_h = (int)(HEIGHT / g->ray.perp_wall_dist);
}

void	raycast(t_game *g, t_map *map)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		get_deltadist(g, x);
		get_sidedist(g);
		dda(g, map);
		draw(g);
		draw2(g);
		draw3(g, x, -1);
	}
	mlx_put_image_to_window(g->mlx, g->win, g->full_img->img, 0, 0);
}
