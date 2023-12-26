#ifndef MAP_CONTROLS_H
#define MAP_CONTROLS_H

typedef struct s_map
{
    char **map;
    char *north;
    char *west;
    char *east;
    char *south;
    char *floor;
    char *ceil;
    int floor_val;
    int ceil_val;
}              t_map;

int file_extension_check(char *map_name);
char **read_map(char *map_name);
void parse_map(t_map *map, char *map_name);
unsigned int	get_color(char *rgb);
int vertical_check(char **map, int *yx);
char **copy_matrix(char **map)
#endif