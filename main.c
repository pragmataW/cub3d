#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cub3d.h"

int main(int argc, char **argv)
{
    t_map *map;

    if (argc < 1)
        exit(printf("Wrong argument count\n"));
    else
    {
        map = malloc(sizeof(t_map) * 1);
        parse_map(map, argv[1]);
        int i = 0;
        while(map->map[i] != NULL)
        {
            printf("%s\n", map->map[i]); 
            i++;
        }
        printf("%s\n", map->ceil);
        printf("%s\n", map->floor);
        printf("%s\n", map->north);
        printf("%s\n", map->west);
        printf("%s\n", map->south);
        printf("%s\n", map->east);
        printf("%d\n", map->ceil_val);
        printf("%d\n", map->floor_val);
    }
}