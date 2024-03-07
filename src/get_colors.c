/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:10:15 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/07 22:28:33 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

static void	comma_count(char *rgb)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (rgb[i] != '\0')
	{
		if (rgb[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		exit(printf("Error\nInvalid color format\n"));
}

static void	check_digit(char *rgb)
{
	int	i;

	i = 0;
	while (rgb[i] != '\0')
	{
		if (!ft_isdigit(rgb[i]) && rgb[i] != ',')
			exit(printf("Error\nInvalid color format\n"));
		i++;
	}
}

static void	check_range(char *rgb)
{
	char	**tmp;
	int		i;

	tmp = ft_split(rgb, ',');
	if (!tmp)
		exit(printf("Error\nInvalid color format\n"));
	i = 0;
	while (tmp[i] != NULL)
	{
		if (ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 255)
		{
			double_free(tmp);
			exit(printf("Error\nInvalid color range\n"));
		}
		i++;
	}
	if (i != 3)
	{
		double_free(tmp);
		exit(printf("Error\nInvalid color format\n"));
	}
	double_free(tmp);
}

unsigned int	get_color(char *rgb)
{
	char			**tmp;
	unsigned int	ret;

	check_digit(rgb);
	comma_count(rgb);
	check_range(rgb);
	tmp = ft_split(rgb, ',');
	ret = (ft_atoi(tmp[0]) * 256 * 256)
		+ (ft_atoi(tmp[1]) * 256) + (ft_atoi(tmp[2]));
	double_free(tmp);
	return (ret);
}
