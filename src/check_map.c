#include "cub3d.h"
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
                i = 0;
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
    int flag;

    y = yx[0];
    x = yx[1];
    flag = 1;
    while(map[y] != NULL)
    {
        row_len = ft_strlen(map[y]);
        if (x > row_len  || map[y][x] == ' ')
            return (0);
        if (map[y][x] == '1')
        {
            flag = 0;
            break;
        }
        y++;
    }
    if (flag)
        return (0);
    y = yx[0];
    while (y >= 0)
    {
        row_len = ft_strlen(map[y]);
        if (x > row_len || map[y][x] == ' ')
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
    int flag;

    y = yx[0];
    x = yx[1];
    flag = 1;
    while(map[y][x] != '\0')
    {
        if (map[y][x] == '\0' || map[y][x] == ' ')
        {
            return (0);
        }
        if (map[y][x] == '1')
        {
            flag = 0;
            break;
        }
        x++;
    }
    if (flag)
        return (0);
    x = yx[1];
    while(x != -1)
    {
        if ((x == 0 && map[y][x] == '0') || map[y][x] == ' ')
            return (0);
        if (map[y][x] == '1')
            return (1);
        x--;
    }
    return (0);
}

void char_control(char **map)
{
    int i;
    int j;
    int row_len;

    i = 0;
    while(map[i] != NULL)
    {
        j = 0;
        row_len = ft_strlen(map[i]);
        while(j < row_len)
        {
            if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ' && map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'W' && map[i][j] != 'E')
            {
                exit(printf("Error\nInvalid character in map\n"));
            }
            j++;
        }
        i++;
    }
} 

void is_passed(char **map)
{
    int *yx;
    int flag;
    char **tmp_map;

    yx = find_free_space(map);
    tmp_map = copy_matrix(map);
    flag = 0;
    while(yx != NULL)
    {
        if (vertical_check(tmp_map, yx) == 0)
        {
            flag = 1;
            free(yx);
            break ;
        }
        free(yx);
        yx = find_free_space(tmp_map);
    }
    double_free(tmp_map);
    if (flag == 1)
        exit(printf("Error\nVertical check failed\n"));
    tmp_map = copy_matrix(map);
    yx = find_free_space(tmp_map);
    while(yx != NULL)
    {
        if (horizontal_check(tmp_map, yx) == 0)
            exit(printf("Error\nHorizontal check failed\n"));
        free(yx);
        yx = find_free_space(tmp_map);
    }
}