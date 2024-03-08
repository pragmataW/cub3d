/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:10:30 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/08 03:55:56 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "cub3d.h"
#include <stdio.h>

int	map_y_len(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

char	**copy_matrix(char **map)
{
	char	**ret;
	int		len;
	int		i;

	len = map_y_len(map);
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (map[i] != NULL)
	{
		ret[i] = ft_strdup(map[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	is_passed2(t_map *map, char **tmp_map, int *yx)
{
	tmp_map = copy_matrix(map->map);
	yx = find_free_space(tmp_map, 0, 0);
	while (yx != NULL)
	{
		if (horizontal_check(tmp_map, yx, yx[0], yx[1]) == 0)
		{
			free(yx);
			double_free(tmp_map);
			free_t_map(map);
			exit(printf("Error\nHorizontal check failed\n"));
		}
		free(yx);
		yx = find_free_space(tmp_map, 0, 0);
	}
	double_free(tmp_map);
}
