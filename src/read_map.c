#include "cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static int count_rows(char *map_name)
{
    int ret;
    int fd;
    char *tmp;
    
    ret = 0;
    fd = open(map_name, O_RDONLY);
    tmp = get_next_line(fd);
    while (tmp != NULL)
    {
        ret++;
        free(tmp);
        tmp = get_next_line(fd);
    }
    return (ret);
}

char **read_map(char *map_name)
{
    int fd;
    int i;
    char **ret;
    char **double_tmp;
    char *tmp;

    fd = open(map_name, O_RDONLY);
    i = 0;
    double_tmp = malloc(sizeof(char *) * (count_rows(map_name) + 1));
    tmp = get_next_line(fd);
    if (tmp == NULL)
        return (NULL);
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
    return (ret);
}
