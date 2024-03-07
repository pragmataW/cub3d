/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:10:24 by yusuf             #+#    #+#             */
/*   Updated: 2024/03/07 21:55:43 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1024
# define HEIGHT 768
# define TEXTURE_W 128
# define TEXTURE_H 128

// LINUX
# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363

// MACOS
// #define W 13
// #define S 1
// #define A 0
// #define D 2
// #define ESC 53
// #define LEFT 123
// #define RIGHT 124

typedef struct s_map
{
	char	**map;
	char	*north;
	char	*west;
	char	*east;
	char	*south;
	char	*floor;
	char	*ceil;
	int		floor_val;
	int		ceil_val;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		*addr;
}	t_img;

typedef struct s_texture
{
	int		line_h;
	double	step;
	double	text_pos;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	int		text_w;
	int		text_h;
}	t_texture;

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	int		step_x;
	int		step_y;
	double	plane_x;
	double	plane_y;
	int		map_x;
	int		map_y;
	int		is_hit;
	int		side;
	double	perp_wall_dist;
	double	wall_x;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		*full_img;
	t_img		*no;
	t_img		*so;
	t_img		*we;
	t_img		*ea;
	t_texture	tex;
	t_map		*map;
	int			w;
	int			s;
	int			a;
	int			d;
	int			l;
	int			r;
	int			floor;
	int			ceil;
	float		speed;
	float		rot_speed;
	t_ray		ray;
}	t_game;

t_game			*init(t_map *map);
int				file_extension_check(char *map_name);
char			**read_map(char *map_name);
t_map			*parse_map(char *map_name);
unsigned int	get_color(char *rgb);
int				vertical_check(char **map, int *yx);
int				horizontal_check(char **map, int *yx);
char			**copy_matrix(char **map);
int				map_y_len(char **map);
void			is_passed(char **map);
void			double_free(char **str);
void			char_control(char **map);
int				release(int key_code, t_game *g);
int				press(int key_code, t_game *g);
int				close_game_by_window(void *game);
void			find_player(t_game *g, t_map *m);
void			raycast(t_game *g, t_map *map);
int				start_game(t_game *g);
void			move_forward_backward(t_game *g);
void			move_left_right(t_game *g);
void			rotate_right(t_game *g);
void			rotate_left(t_game *g);
void			draw(t_game *g);
void			draw2(t_game *g);
void			draw3(t_game *g, int x, int y);
void			free_game(t_game *g);
#endif