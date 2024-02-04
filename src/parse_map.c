#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

static int	is_valid1(char *str)
{
	static int	no_flag;
	static int	so_flag;
	static int	we_flag;

	if (!ft_strcmp(str, "NO") && no_flag == 0)
	{
		no_flag = 1;
		return (1);
	}
	if (!ft_strcmp(str, "SO") && so_flag == 0)
	{
		so_flag = 1;
		return (1);
	}
	if (!ft_strcmp(str, "WE") && we_flag == 0)
	{
		we_flag = 1;
		return (1);
	}
	return (0);
}

static int	is_valid2(char *str)
{
	static int	ea_flag;
	static int	c_flag;
	static int	f_flag;

	if (!ft_strcmp(str, "EA") && ea_flag == 0)
	{
		ea_flag = 1;
		return (1);
	}
	if (!ft_strcmp(str, "C") && c_flag == 0)
	{
		c_flag = 1;
		return (1);
	}
	if (!ft_strcmp(str, "F") && f_flag == 0)
	{
		f_flag = 1;
		return (1);
	}
	return (0);
}

static int	check_and_get(t_map *map, char **regex)
{
	if (is_valid1(regex[0]) || is_valid2(regex[0]))
	{
		if (!ft_strcmp(regex[0], "NO"))
			map->north = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "SO"))
			map->south = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "WE"))
			map->west = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "EA"))
			map->east = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "C"))
			map->ceil = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "F"))
			map->floor = ft_strdup(regex[1]);
	}
	else
		return (0);
	return (1);
}


static int	pair_map(t_map *map, char **full_map)
{
	int		i;
	char	**tmp;

	i = 0;
	while (i < 6 && full_map && full_map[i])
	{
		tmp = ft_split(full_map[i], ' ');
		if (!check_and_get(map, tmp))
		{
            double_free(tmp);
			double_free(full_map);
			exit(printf("Error: invalid map format\n"));
		}
		if (tmp)
			double_free(tmp);
		++i;
	}
	return (i);
}

void parse_map(t_map *map, char *map_name)
{
    char **tmp_map;
    int i;
    int len;
    int j;

    tmp_map = read_map(map_name);
    if (!tmp_map)
        exit(printf("Invalid map format\n"));
    i = pair_map(map, tmp_map);
    len = 0;
    while(tmp_map && tmp_map[len])
        len++;
    len -= i;
    map->map = malloc(sizeof(char *) * (len + 1));
    map->map[len - 1] = NULL;
    j = 0;
    while(tmp_map && tmp_map[i])
    {
        map->map[j] = tmp_map[i];
        j++;
        i++;
    }
    map->map[j] = NULL;
    map->ceil_val = get_color(map->ceil);
    map->floor_val = get_color(map->floor);
}
