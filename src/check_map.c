/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:10:27 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/08 13:14:11 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include "../libft/libft.h"

int	*find_free_space(char **map, int i, int j)
{
	int	*ret;

	ret = malloc(sizeof(int) * 2);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E' || map[i][j] == 'N')
			{
				ret[0] = i;
				ret[1] = j;
				map[i][j] = '2';
				i = 0;
				return (ret);
			}
			j++;
		}
		i++;
	}
	free(ret);
	return (NULL);
}

int	vertical_check(char **map, int *yx, int y, int x)
{
	int	flag;

	flag = 1;
	while (map[y] != NULL)
	{
		if (x > ft_strlen(map[y]) || map[y][x] == ' ')
			return (0);
		if (map[y++][x] == '1')
		{
			flag = 0;
			break ;
		}
	}
	if (flag)
		return (0);
	y = yx[0];
	while (y >= 0)
	{
		if (x > ft_strlen(map[y]) || map[y][x] == ' ')
			return (0);
		if (map[y--][x] == '1')
			return (1);
	}
	return (0);
}

int	horizontal_check(char **map, int *yx, int y, int x)
{
	int	flag;

	flag = 1;
	while (map[y][x] != '\0')
	{
		if (map[y][x] == '\0' || map[y][x] == ' ')
			return (0);
		if (map[y][x++] == '1')
		{
			flag = 0;
			break ;
		}
	}
	if (flag)
		return (0);
	x = yx[1];
	while (x != -1)
	{
		if ((x == 0 && map[y][x] == '0') || map[y][x] == ' ')
			return (0);
		if (map[y][x--] == '1')
			return (1);
	}
	return (0);
}

void	char_control(t_map *map)
{
	int	i;
	int	j;
	int	row_len;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		row_len = ft_strlen(map->map[i]);
		while (j < row_len)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != ' '
				&& map->map[i][j] != 'N' && map->map[i][j] != 'S'
				&& map->map[i][j] != 'W' && map->map[i][j] != 'E')
			{
				free_t_map(map);
				exit(printf("Error\nInvalid character in map\n"));
			}
			j++;
		}
		i++;
	}
}

void	is_passed(t_map *map)
{
	int		*yx;
	int		flag;
	char	**tmp_map;

	yx = find_free_space(map->map, 0, 0);
	tmp_map = copy_matrix(map->map);
	flag = 0;
	while (yx != NULL)
	{
		if (vertical_check(tmp_map, yx, yx[0], yx[1]) == 0)
		{
			flag = 1;
			free(yx);
			break ;
		}
		free(yx);
		yx = find_free_space(tmp_map, 0, 0);
	}
	double_free(tmp_map);
	if (flag == 1)
	{
		free_t_map(map);
		exit(printf("Error\nVertical check failed\n"));
	}
	is_passed2(map, tmp_map, yx);
}
