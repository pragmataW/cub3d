#include "../libft/libft.h"
#include <stdlib.h>

unsigned int	get_color(char *rgb)
{
    char **tmp;
    unsigned int ret;

    tmp = ft_split(rgb, ',');
	ret = (ft_atoi(tmp[0]) * 256 * 256)
		+ (ft_atoi(tmp[1]) * 256) + (ft_atoi(tmp[2]));
	return (ret);
}