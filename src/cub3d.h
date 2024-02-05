#ifndef CUB3D_H
#define CUB3D_H

#define WIDTH 1024
#define HEIGHT 768

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

typedef struct s_img
{
    void *img;
    int *addr;
}               t_img;

typedef struct s_game
{
    void *mlx;
    void *win;
    t_img *full_img;
    t_img *no;
    t_img *so;
    t_img *we;
    t_img *ea;
    int floor;
    int ceil;

}               t_game;



t_game *init(t_map *map);
int file_extension_check(char *map_name);
char **read_map(char *map_name);
void parse_map(t_map *map, char *map_name);
unsigned int	get_color(char *rgb);
int vertical_check(char **map, int *yx);
int horizontal_check(char **map, int *yx);
char **copy_matrix(char **map);
int map_y_len(char **map);
void is_passed(char **map);
void double_free(char **str);
void char_control(char **map);

#endif