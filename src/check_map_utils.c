/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:10:30 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/07 19:10:31 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
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
