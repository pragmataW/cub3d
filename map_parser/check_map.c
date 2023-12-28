#include "../cub3d.h"
#include <stdio.h>
#include "../libft/libft.h"

int *find_free_space(char **map)
{
    int i;
    int j;
    int *ret;
    
    i = 0;
    ret = malloc(sizeof(int) * 2);
    while (map[i] != NULL)
    {
        j = 0;
        while(map[i][j] != '\0')
        {
            if (map[i][j] == '0' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'N')
            {
                ret[0] = i;
                ret[1] = j;
                map[i][j] = '2';
                return ret;
            }
            j++;
        }
        i++;
    }
    free(ret);
    return (NULL);
}

int vertical_check(char **map, int *yx)
{
    int y;
    int x;
    int row_len;

    y = yx[0];
    x = yx[1];
    while(map[y] != NULL)
    {
        row_len = ft_strlen(map[y]);
        if (x > row_len  || map[y][x] == ' ' )
            return (0);
        if (map[y][x] == '1')
            break;
        y++;
    }
    y = yx[0];
    while (y >= 0)
    {
        row_len = ft_strlen(map[y]);
        if (x > row_len  || map[y][x] == ' ')
            return (0);
        if (map[y][x] == '1')
            return (1);
        y--;
    }
    return (0);
}

int horizontal_check(char **map, int *yx)
{
    int y;
    int x;

    y = yx[0];
    x = yx[1];
    while(map[y][x] != '\0')
    {
        if (map[y][x] == '\0' || map[y][x] == ' ')
            return 0;
        if (map[y][x] == '1')
            break ;
        x++;
    }
    x = yx[1];
    while (x >= 0)
    {
        if ( x == 0 || map[y][x] == ' ')
            return 0;
        if (map[y][x] == '1')
            return 1;
            x--;
    }
    return (1);
}

int is_valid(char **map)
{
    int *yx;
    char **tmp_map;

    yx = find_free_space(map);
    tmp_map = copy_matrix(map);
    while(yx != NULL)
    {
        if (vertical_check(map, yx) == 0)
            return (0);
        free(yx);
        yx = find_free_space(map);
    }
    double_free(tmp_map);
    tmp_map = copy_matrix(map);
    while(yx != NULL)
    {
        if (horizontal_check(map, yx) == 0)
            return (0);
        free(yx);
        yx = find_free_space(map);
    }
    return (1);
}