/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:09:55 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/07 22:29:32 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

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

void	free_game(t_game *g)
{
	if (g->map->map)
		double_free(g->map->map);
	if (g->map->north)
		free(g->map->north);
	if (g->map->south)
		free(g->map->south);
	if (g->map->west)
		free(g->map->west);
	if (g->map->east)
		free(g->map->east);
	if (g->map->floor)
		free(g->map->floor);
	if (g->map->ceil)
		free(g->map->ceil);
}

void	find_player(t_game *g, t_map *m)
{
	int	i;
	int	j;

	i = 0;
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
			j++;
		}
		i++;
	}
}
