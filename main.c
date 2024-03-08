/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:09:33 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/08 07:07:02 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "src/cub3d.h"
#include "mlx/mlx.h"
#include <stdlib.h>

int	start_game(t_game *g)
{
	move_forward_backward(g);
	move_left_right(g);
	rotate_right(g);
	rotate_left(g);
	raycast(g, g->map);
	return (0);
}

void	main_controls(t_map *map, char *map_name)
{
	if (player_counter(map) == 0)
	{
		free_t_map(map);
		exit(printf("Error\nWrong player count\n"));
	}
	if (file_extension_check(map_name) == 0)
	{
		free_t_map(map);
		exit(printf("Error\nWrong file extension\n"));
	}
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
		char_control(map);
		main_controls(map, argv[1]);
		is_passed(map);
		game = init(map);
		find_player(game, map, 0, 0);
		mlx_hook(game->win, 2, 1L << 0, press, game);
		mlx_hook(game->win, 3, 1L << 1, release, game);
		mlx_hook(game->win, 17, 0, close_game_by_window, game);
		mlx_loop_hook(game->mlx, &start_game, game);
		mlx_loop(game->mlx);
	}
}
