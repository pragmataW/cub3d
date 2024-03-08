/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:10:01 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/08 07:41:32 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include <stdio.h>

static int	count_rows(char *map_name)
{
	int		ret;
	int		fd;
	char	*tmp;

	ret = 0;
	fd = open(map_name, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		ret++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (ret);
}

char	**read_map(char *map_name)
{
	int		fd;
	int		i;
	char	**ret;
	char	**double_tmp;
	char	*tmp;

	fd = open(map_name, O_RDONLY);
	i = 0;
	tmp = get_next_line(fd);
	if (tmp == NULL)
		exit(printf("Invalid map format\n"));
	double_tmp = malloc(sizeof(char *) * (count_rows(map_name) + 1));
	while (tmp != NULL)
	{
		double_tmp[i] = tmp;
		tmp = get_next_line(fd);
		i++;
	}
	double_tmp[i] = NULL;
	tmp = ft_merge_str(double_tmp, '\n');
	ret = ft_split(tmp, '\n');
	double_free(double_tmp);
	free(tmp);
	return (ret);
}
