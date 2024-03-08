/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:10:15 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/08 03:50:12 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "cub3d.h"

static int	comma_count(char *rgb)
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
		return (0);
	return (1);
}

static int	check_digit(char *rgb)
{
	int	i;

	i = 0;
	while (rgb[i] != '\0')
	{
		if (!ft_isdigit(rgb[i]) && rgb[i] != ',')
			return (0);
		i++;
	}
	return (1);
}

static int	check_range(char *rgb)
{
	char	**tmp;
	int		i;

	tmp = ft_split(rgb, ',');
	if (!tmp)
		return (0);
	i = 0;
	while (tmp[i] != NULL)
	{
		if (ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 255)
		{
			double_free(tmp);
			return (0);
		}
		i++;
	}
	if (i != 3)
	{
		double_free(tmp);
		return (0);
	}
	double_free(tmp);
	return (1);
}

int	get_color(char *rgb)
{
	char			**tmp;
	unsigned int	ret;
	int				flag;

	flag = check_digit(rgb);
	if (!flag)
		return (-1);
	flag = comma_count(rgb);
	if (!flag)
		return (-1);
	flag = check_range(rgb);
	if (!flag)
		return (-1);
	tmp = ft_split(rgb, ',');
	ret = (ft_atoi(tmp[0]) * 256 * 256)
		+ (ft_atoi(tmp[1]) * 256) + (ft_atoi(tmp[2]));
	double_free(tmp);
	return (ret);
}
