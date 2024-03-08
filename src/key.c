/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:10:10 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/08 03:00:40 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int	press(int key_code, t_game *g)
{
	if (key_code == ESC)
	{
		free_t_map(g->map);
		free_game(g);
		printf("Bye!\n");
		exit(0);
	}
	if (key_code == W)
		g->w = 1;
	if (key_code == S)
		g->s = 1;
	if (key_code == A)
		g->a = 1;
	if (key_code == D)
		g->d = 1;
	if (key_code == RIGHT)
		g->r = 1;
	if (key_code == LEFT)
		g->l = 1;
	return (0);
}

int	release(int key_code, t_game *g)
{
	if (key_code == W)
		g->w = 0;
	if (key_code == S)
		g->s = 0;
	if (key_code == A)
		g->a = 0;
	if (key_code == D)
		g->d = 0;
	if (key_code == RIGHT)
		g->r = 0;
	if (key_code == LEFT)
		g->l = 0;
	return (0);
}

int	close_game_by_window(void *game)
{
	printf("Bye!\n");
	free_t_map(((t_game *)game)->map);
	free_game((t_game *)game);
	exit(0);
}
