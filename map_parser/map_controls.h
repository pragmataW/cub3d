#ifndef MAP_CONTROLS_H
#define MAP_CONTROLS_H

int file_extension_check(char *map_name);
int count_rows(char *map_name);
char **read_map(char *map_name);
#endif