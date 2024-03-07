/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:10:21 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/07 19:10:22 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	move_forward_backward(t_game *g)
{
	if (g->w)
	{
		if (g->map->map[(int)(g->ray.pos_y)][(int)(g->ray.pos_x + g->ray.dir_x
			* g->speed)] != 49)
			g->ray.pos_x += g->ray.dir_x * g->speed;
		if (g->map->map[(int)(g->ray.pos_y + g->ray.dir_y * g->speed)]
			[(int)(g->ray.pos_x)] != 49)
			g->ray.pos_y += g->ray.dir_y * g->speed;
	}
	if (g->s)
	{
		if (g->map->map[(int)(g->ray.pos_y)][(int)(g->ray.pos_x - g->ray.dir_x
			* g->speed)] != 49)
			g->ray.pos_x -= g->ray.dir_x * g->speed;
		if (g->map->map[(int)(g->ray.pos_y - g->ray.dir_y * g->speed)]
			[(int)(g->ray.pos_x)] != 49)
			g->ray.pos_y -= g->ray.dir_y * g->speed;
	}
}

void	move_left_right(t_game *g)
{
	if (g->a)
	{
		if (g->map->map[(int)(g->ray.pos_y - g->ray.plane_y * g->speed)]
			[(int)(g->ray.pos_x)] != 49)
			g->ray.pos_y -= g->ray.plane_y * g->speed;
		if (g->map->map[(int)(g->ray.pos_y)][(int)(g->ray.pos_x - g->ray.plane_x
			* g->speed)] != 49)
			g->ray.pos_x -= g->ray.plane_x * g->speed;
	}
	if (g->d)
	{
		if (g->map->map[(int)(g->ray.pos_y)][(int)(g->ray.pos_x + g->ray.plane_x
			* g->speed)] != 49)
			g->ray.pos_x += g->ray.plane_x * g->speed;
		if (g->map->map[(int)(g->ray.pos_y + g->ray.plane_y * g->speed)]
			[(int)(g->ray.pos_x)] != 49)
			g->ray.pos_y += g->ray.plane_y * g->speed;
	}
}

void	rotate_right(t_game *g)
{
	double	olddir_x;
	double	oldplane_x;

	if (g->r)
	{
		olddir_x = g->ray.dir_x;
		g->ray.dir_x = g->ray.dir_x * cos(g->rot_speed) - g->ray.dir_y
			* sin(g->rot_speed);
		g->ray.dir_y = olddir_x * sin(g->rot_speed) + g->ray.dir_y
			* cos(g->rot_speed);
		oldplane_x = g->ray.plane_x;
		g->ray.plane_x = g->ray.plane_x * cos(g->rot_speed) - g->ray.plane_y
			* sin(g->rot_speed);
		g->ray.plane_y = oldplane_x * sin(g->rot_speed) + g->ray.plane_y
			* cos(g->rot_speed);
	}
}

void	rotate_left(t_game *g)
{
	double	olddir_x;
	double	oldplane_x;

	if (g->l)
	{
		olddir_x = g->ray.dir_x;
		g->ray.dir_x = g->ray.dir_x * cos(g->rot_speed) + g->ray.dir_y
			* sin(g->rot_speed);
		g->ray.dir_y = -olddir_x * sin(g->rot_speed) + g->ray.dir_y
			* cos(g->rot_speed);
		oldplane_x = g->ray.plane_x;
		g->ray.plane_x = g->ray.plane_x * cos(g->rot_speed) + g->ray.plane_y
			* sin(g->rot_speed);
		g->ray.plane_y = -oldplane_x * sin(g->rot_speed) + g->ray.plane_y
			* cos(g->rot_speed);
	}
}
