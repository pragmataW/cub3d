/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:43:50 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/08 03:56:20 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

void	parse_map_extra(char **tmp_map, t_map *map, int i)
{
	int	j;

	j = 0;
	while (tmp_map && tmp_map[i])
		map->map[j++] = ft_strdup(tmp_map[i++]);
	map->map[j] = NULL;
	map->ceil_val = get_color(map->ceil);
	map->floor_val = get_color(map->floor);
	if (map->ceil_val == -1 || map->floor_val == -1)
	{
		free_t_map(map);
		double_free(tmp_map);
		exit(printf("Error: invalid color format\n"));
	}
	double_free(tmp_map);
}
