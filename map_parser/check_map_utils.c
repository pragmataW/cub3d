#include "map_controls.h"
#include "../libft/libft.h"
#include <stdlib.h>

char **copy_matrix(char **map)
{
    char **ret;
    int i;

    ret = malloc(sizeof(char *) * (map_y_len(map) + 1));
    i = 0;
    while (map[i] != NULL)
    {
        ret[i] = ft_strdup(map[i]);
        i++;
    }
    return (ret);
}