/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:11:51 by fakman            #+#    #+#             */
/*   Updated: 2024/03/07 19:26:53 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../mlx/mlx.h"
#include <math.h>

void	draw(t_game *g)
{
	g->tex.draw_start = -g->tex.line_h / 2 + HEIGHT / 2;
	if (g->tex.draw_start < 0)
		g->tex.draw_start = 0;
	g->tex.draw_end = g->tex.line_h / 2 + HEIGHT / 2;
	if (g->tex.draw_end >= HEIGHT)
		g->tex.draw_end = HEIGHT - 1;
	if (g->ray.side == 0)
		g->ray.wall_x = g->ray.pos_y + g->ray.perp_wall_dist * g->ray.raydir_y;
	else
		g->ray.wall_x = g->ray.pos_x + g->ray.perp_wall_dist * g->ray.raydir_x;
	g->ray.wall_x = g->ray.wall_x - (int)g->ray.wall_x;
}

void	draw2(t_game *g)
{
	g->tex.tex_x = (int)(g->ray.wall_x * (double)g->tex.text_w);
	if (g->ray.side == 0 && g->ray.raydir_x < 0)
		g->tex.tex_x = g->tex.text_w - g->tex.tex_x - 1;
	if (g->ray.side == 1 && g->ray.raydir_y > 0)
		g->tex.tex_x = g->tex.text_w - g->tex.tex_x - 1;
	g->tex.step = 1.0 * g->tex.text_h / g->tex.line_h;
	g->tex.text_pos = (g->tex.draw_start - HEIGHT / 2 + g->tex.line_h / 2)
		* g->tex.step;
}

void	draw3(t_game *g, int x, int y)
{
	while (++y < HEIGHT)
	{
		g->tex.tex_y = (int)g->tex.text_pos;
		if (y < g->tex.draw_start)
			g->full_img->addr[y * WIDTH + x] = g->ceil;
		else if (y > g->tex.draw_end)
			g->full_img->addr[y * WIDTH + x] = g->floor;
		else
		{
			if (g->ray.side == 1 && g->ray.raydir_y < 0)
				g->full_img->addr[y * WIDTH + x] = g->so->addr[g->tex.text_h
					* g->tex.tex_y + g->tex.tex_x];
			else if (g->ray.side == 1 && g->ray.raydir_y > 0)
				g->full_img->addr[y * WIDTH + x] = g->no->addr[g->tex.text_h
					* g->tex.tex_y + g->tex.tex_x];
			if (g->ray.side == 0 && g->ray.raydir_x < 0)
				g->full_img->addr[y * WIDTH + x] = g->we->addr[g->tex.text_h
					* g->tex.tex_y + g->tex.tex_x];
			else if (g->ray.side == 0 && g->ray.raydir_x > 0)
				g->full_img->addr[y * WIDTH + x] = g->ea->addr[g->tex.text_h
					* g->tex.tex_y + g->tex.tex_x];
			g->tex.text_pos += g->tex.step;
		}
	}
}
