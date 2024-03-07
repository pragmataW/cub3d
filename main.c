/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:09:33 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/07 21:05:21 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "src/cub3d.h"
#include "mlx/mlx.h"
#include "libft/libft.h"

int	start_game(t_game *g)
{
	move_forward_backward(g);
	move_left_right(g);
	rotate_right(g);
	rotate_left(g);
	raycast(g, g->map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	*map;

	if (argc != 2)
		exit(printf("Wrong argument count\n"));
	else
	{
		map = parse_map(argv[1]);
		char_control(map->map);
		is_passed(map->map);
		game = init(map);
		game->map = map;
		find_player(game, map);
		mlx_hook(game->win, 2, 1L << 0, press, game);
		mlx_hook(game->win, 3, 1L << 1, release, game);
		mlx_hook(game->win, 17, 0, close_game_by_window, game);
		mlx_loop_hook(game->mlx, &start_game, game);
		mlx_loop(game->mlx);
	}
}
