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
        int a[2] = {3, 5};
        printf("%d\n", vertical_check(map->map, a));
    }
}