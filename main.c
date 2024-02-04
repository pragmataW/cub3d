#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "src/cub3d.h"

int main(int argc, char **argv)
{
    t_map *map;

    if (argc < 1)
        exit(printf("Wrong argument count\n"));
    else
    {
        map = malloc(sizeof(t_map) * 1);
        parse_map(map, "maps/31.cub");
        printf("%d\n", is_passed(map->map));
    }
}