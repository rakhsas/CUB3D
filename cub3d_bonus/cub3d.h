/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:40:06 by aankote           #+#    #+#             */
/*   Updated: 2023/06/19 12:18:11 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "stdbool.h"
# define WIN_X 1920
# define WIN_Y 1080
# define CARE 64
# define P_SIZE 4
# define MAP_X 300
# define MAP_Y 300

/********************COLORS*****************/
# define WAY 0x00CDB82F
# define PLAYER 0x00CAF5FA
# define LINE 0x00AFAD9D
# define WALL 0x00330019
# define WALL 0x00330019
# define SKY 0x00C4F6FC
# define FLOOR 0x0093FFBE
# define RED 0x00FF0000
# define GREEN 0x0000CA44
# define BLUE 0x000000FF
# define YELLOW 0x00FFFF00
/**********MATH****************************/
# define PI 3.14159265359
# define MOVE_SPEED 12

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		map_x;
	int		map_y;
}	t_win;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_player
{
	double	px_pos;
	double	py_pos;
	double	walk_dir;
	double	turn_dir;
	double	rot_dir;
	double	movestep;
	double	routation_ang;
	double	ray_angle;
}			t_player;

typedef struct s_cords
{
	double	xinterc_hor;
	double	yinterc_hor;
	double	xinterc_ver;
	double	yinterc_ver;
	double	xb_hor;
	double	yb_hor;
	double	xb_ver;
	double	yb_ver;
	double	xsteps_hor;
	double	ysteps_ver;
	double	ver_dx;
	double	ver_dy;
	double	hor_dx;
	double	hor_dy;
}			t_cord;

typedef struct s_wall
{
	double	distanceprojplane;
	int		ceiling_color;
	int		floor_color;
	int		is_horiz_hit;
	int		texture_x;
	int		texture_y;
	double	heightwall;
	double	topwall;
	double	bottomwall;
}			t_wall;

typedef struct s_ray
{
	float	xhit;
	float	yhit;
	float	distance;
}	t_ray;

typedef struct s_data
{
	struct s_map	*map;
	t_win			win;
	t_img			img;
	t_img			main_img;
	t_player		player;
	t_cord			cords;
	t_wall			wall;
	t_ray			ray;
}	t_data;

typedef struct s_pl
{
	int		p_posx;
	int		p_posy;
	char	p_dir;
}	t_pl;

typedef struct s_textures
{
	int				no;
	int				so;
	int				ea;
	int				we;
	t_img			*no_img;
	t_img			*so_img;
	t_img			*ea_img;
	t_img			*we_img;
	char			**no_map;
}	t_textures;

typedef struct s_map
{
	char			**map;
	char			**map_copy;
	char			**c_tab;
	int				len_vert;
	int				len_hori;
	int				c_p[3];
	int				f_p[3];
	int				height;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*f;
	char			*c;
	int				final_f;
	int				final_c;
	t_pl			*player;
	t_textures		*textures;
}	t_map;

int				ft_exit(void *key);
int				ft_key_hook(int key, t_data *data);

/***********************Mini Map**************************/

int				draw_squart(t_data *data, int x, int y);
int				draw_lines(t_data *data);
int				draw_player(t_data *data);
void			draw_map(t_data *data);
void			create_map(t_data *data);
void			draw_p_dir(t_data *data);

/***********************movements************************/
int				move_down(t_data *data);
int				move_up(t_data *data);
int				move_left(t_data *data);
int				move_right(t_data *data);
int				initializ(t_data *data);

/***********************UTILS*****************************/
int				create_window(t_win *win, t_data *data);
void			get_player_pos(t_data *data);
void			draw_ray(t_data *data, double x, double y, int color);
double			rad(double deg);
double			deg(double rad);
void			draw_rays(t_data *data);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				is_player(int c);
void			get_dimensions(t_data *data);
void			angle_adjust(double *ray_angle);
/***********************MOVEMENTS***********************/
int				update_turn(t_data *data);
int				update_walk(t_data *data);
int				update_walk_rl(t_data *data);
int				get_intercepts_ver(t_data *data);
double			check_intersictions(t_data *data);

/***********************CASTING RAYS AND WALLS**********/

int				hit_ver_wall(t_data *data);
int				hit_hor_wall(t_data *data);
int				get_intercepts(t_data *data);
void			draw_things(t_data *data);
void			draw_win(t_data *data);
void			draw_sky(t_data *data);
void			draw_rays(t_data *data);
int				get_second_ver_cord(t_data *data);

/***********************PARSSING************************/

int				check_for_chars(char *line);
int				check_extension(char *str);
void			init(t_map *s_map);
void			parse(char **map);
char			**fill_map(int fd);
char			*free_join(char *s1, char *s2);
void			get_infos_from_map(t_map *s_map);
void			get_specified_data(t_map *s_map);
void			skip_useless_data(t_map *s_map);
char			*ft_strtrim_free(char *str, char *rts);
int				bubble_sort(char **s1);
void			parse_first_part(t_map *s_map, int fd);
void			check_for_textures_extension(t_map *s_map);
void			check_for_textures_path(t_map *s_map);
char			*test(char *str);
void			check_for_max_255(char	*str, int *c_p);
void			check_border_top(t_map *s_map);
void			make_the_map_rectangle(t_map *s_map, int max);
void			check_if_spaces(t_map *s_map);
int				ft_check_right_top(t_map *s_map, int i, int j, int flag);
int				ft_check_left_bottom(t_map *s_map, int i, int j, int flag);
int				get_max_len(t_map *s_map);
void			check_for_unwanted_chars(t_map *s_map);
void			make_the_map_rectangle(t_map *s_map, int max);
void			get_map(t_map *s_map);
void			init_sec_part(t_map *s_map);
void			draw_floor(t_data *data);
void			draw_sky(t_data *data);
void			generate_3d(t_data *data, int x);
void			do_projection(t_data *data, int x, double ds);
void			configure_data(t_data *data, t_img *tex);
int				ft_mouse(int button, int x, int y, t_data *data);

#endif