#include "map_controls.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

int map_y_len(char **map)
{
    int i;

    i = 0;
    while(map[i] != NULL)
        i++;
    return i;
}

char **copy_matrix(char **map)
{
    char **ret;
    int len;
    int i;

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