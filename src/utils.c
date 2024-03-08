/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:09:55 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/08 13:03:21 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"
#include "../mlx/mlx.h"

void	double_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
}

void	free_t_map(t_map *map)
{
	if (map->map)
		double_free(map->map);
	if (map->north)
		free(map->north);
	if (map->south)
		free(map->south);
	if (map->west)
		free(map->west);
	if (map->east)
		free(map->east);
	if (map->floor)
		free(map->floor);
	if (map->ceil)
		free(map->ceil);
	if (map)
		free(map);
}

void	free_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->no->img);
	mlx_destroy_image(game->mlx, game->so->img);
	mlx_destroy_image(game->mlx, game->we->img);
	mlx_destroy_image(game->mlx, game->ea->img);
	mlx_destroy_image(game->mlx, game->full_img->img);
	free(game->no);
	free(game->so);
	free(game->we);
	free(game->ea);
	free(game->full_img);
	free(game);
}

static void	find_player_extra(t_game *g, t_map *m, int i, int j)
{
	if (m->map[i][j] == 'S')
	{
		g->ray.dir_x = 0;
		g->ray.dir_y = 1;
		g->ray.plane_x = -0.66;
		g->ray.plane_y = 0;
	}
	if (m->map[i][j] == 'W')
	{
		g->ray.dir_x = -1;
		g->ray.dir_y = 0;
		g->ray.plane_x = 0;
		g->ray.plane_y = -0.66;
	}
	if (m->map[i][j] == 'E')
	{
		g->ray.dir_x = 1;
		g->ray.dir_y = 0;
		g->ray.plane_x = 0;
		g->ray.plane_y = 0.66;
	}
}

void	find_player(t_game *g, t_map *m, int i, int j)
{
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'N' || m->map[i][j] == 'S'
				|| m->map[i][j] == 'W' || m->map[i][j] == 'E')
			{
				g->ray.pos_x = j + 0.5;
				g->ray.pos_y = i + 0.5;
				g->ray.map_x = i;
				g->ray.map_y = j;
				if (m->map[i][j] == 'N')
				{
					g->ray.dir_x = 0;
					g->ray.dir_y = -1;
					g->ray.plane_x = 0.66;
					g->ray.plane_y = 0;
				}
				find_player_extra(g, m, i, j);
			}
			j++;
		}
		i++;
	}
}
