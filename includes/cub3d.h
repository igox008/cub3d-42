/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:07 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 19:23:19 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "../g_col/g_collector.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include "../MLX42/include/MLX42.h"
# include <stdio.h>
# include <pthread.h>
# include <math.h>
# include <signal.h>
# include <stdint.h>
# define FOV 1.0471975511965976

# define HEIGHT 1080
# define WIDTH 1920
# define SCL 0.2

typedef struct s_t_point___
{
	double_t	x;
	double_t	y;
}	t_point_;

typedef struct s____t_globl_
{
	__INT32_TYPE__	facing_down;
	__INT32_TYPE__	facing_up;
	__INT32_TYPE__	facing_right;
	__INT32_TYPE__	facing_left;
	double_t		angle_view;
}	t_globl_;

typedef struct s___rays
{
	__INT32_TYPE__	index;
	double_t		distance;
	t_point_		coord_hit_h;
	t_point_		coord_hit_v;
	t_point_		coord_hit;
	double_t		angle_ray;
	t_globl_		*data;
	bool			is_vert;
	bool			is_door;
	bool			hit_door_v;
	bool			hit_door_h;
	int				cnt_hit_door;
}	t_rays_;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
	int		hex;
	bool	set;
}	t_rgb;

typedef struct s_corr
{
	double_t	x;
	double_t	y;
}	t_corr;

typedef struct s_var
{
	int				y;
	int				x;
	int				y_p;
	int				x_p;
	int				y_i;
	int				x_i;
	int				y_v;
	int				x_v;
	int				offst_x;
	int				offst_y;
	double_t		dx;
	double_t		dy;
	mouse_mode_t	mode;
	double_t		r;
	char			c;
	bool			b;
}	t_var;

typedef struct s_img
{
	mlx_image_t		*img;
	mlx_texture_t	*txtr;
	unsigned int	*pxls;
}	t_img;

typedef struct s_game
{
	char			**map;
	char			*so;
	t_img			i_so;
	char			*no;
	t_img			i_no;
	char			*we;
	t_img			i_we;
	char			*ea;
	t_img			i_ea;
	t_img			door;
	t_rgb			floor;
	t_rgb			ceiling;
	t_img			*mini_map;
	t_globl_		*data;
	double_t		ratio;
	mlx_t			*mlx;
	mlx_texture_t	*fp;
	t_img			wall;
	mlx_image_t		*plyr_img;
	int				max_len;
	int				p_cnt;
	char			*last;
	int				w;
	int				h;
	char			p_view;
	t_corr			p_pos;
	t_img			*img;
	double_t		angle_view;
	double_t		rotation_speed;
	t_rays_			*ray;
	t_var			v;
	double_t		wall_h;
	bool			full_map;
	mlx_texture_t	**manjal;
	bool			hayad;
	bool			allo;
	bool			stop;
	pthread_t		thrd;
	pthread_mutex_t	mtx;
}	t_game;

typedef struct s__General
{
	t_globl_	*global;
	t_rays_		*ray;
	t_game		*game;
	t_img		*img;
}	t_General;

typedef struct s_var_hor
{
	__INT32_TYPE__	found_horz_wal_hit;
	__INT32_TYPE__	found_vert_wal_hit;
	double_t		inity;
	double_t		initx;
	double_t		stepy;
	double_t		stepx;
	double_t		step_next_x;
	double_t		step_next_y;
}	t_var_hor;

# define ESC 53
# define UP 13
# define RIGHT 2
# define LEFT 0
# define DOWN 1
# define R 124
# define L 123
# define TILE_SIZE 320
# define SPD 30
# define PRPL 0x800080
# define BLUE 0x0000FF
# define GRAY 0x808080
# define MINI_MAP_SIZE 400
# define MN "./textures/manjal/manjal.png"
# define MN1 "./textures/manjal/manjal1.png"
# define MN2 "./textures/manjal/manjal2.png"
# define MN3 "./textures/manjal/manjal3.png"
# define MN4 "./textures/manjal/manjal4.png"
# define MN5 "./textures/manjal/manjal5.png"
# define MN6 "./textures/manjal/manjal6.png"
# define MN7 "./textures/manjal/manjal7.png"

void			innit_data(t_game *game);
bool			mlx_engine(t_game *game);
bool			parcing(char *file, t_game *game);
char			*get_n_space(int n);
bool			check_line(char **map, int y, t_game *game);
char			*till_char(char *line);
bool			ft_isspace(char c);
bool			is_rgb(char *line);
bool			parse_rgb(char **arr, char *line, t_rgb *rgb);
bool			is_valid_rgb(int rgb, char *s);
bool			check_assets(t_game *game);
bool			final_map(t_game *game, char *last, int fd);
bool			last_first(char *s);
bool			mdl_line(char *s);
bool			final_check(char **map, t_game *game);
void			set_w_h(t_game *game);
uint32_t		get_rgba(int r, int g, int b, int a);
void			red_x(void *ptr);
int				render_map(t_game *g, t_img *m, t_var v);
int				render_game(t_game *game);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				put_player(t_game *game, t_img *img);
double_t		get_ratio(t_game *game, double_t new_size);
void			clear_img(mlx_image_t *img);
void			draw_rect(t_img *img, t_var v, int color);
int				render_ray(t_rays_ *ray, t_game *game, int i);
void			listen_hook(void *ptr);
void			key_up_down(t_game *game);
void			key_left_right(t_game *game);
void			key_rl(t_game *game);
__INT32_TYPE__	cast_all_rays(t_game *game, t_globl_ *data);
double_t		dis_between_to_points(double_t xa, double_t ya, \
				double_t xb, double_t yb);
void			ray_facing(t_rays_ *ray, t_globl_ *data);
double_t		normalize_angle(double angle);
bool			has_wall_at_v(double_t i, double_t j, \
				t_game *game, t_rays_ *ray);
bool			has_wall_at_h(double_t i, double_t j, \
				t_game *game, t_rays_ *ray);
void			init_h(double_t *initX, double_t *initY, \
				t_game *game, t_rays_ *ray);
void			step_h(double_t *stepX, double_t *stepY, t_rays_ *ray);
void			init_v(double_t *initX, double_t *initY, \
				t_game *game, t_rays_ *ray);
void			step_v(double_t *stepX, double_t *stepY, t_rays_ *ray);
double_t		get_view(char dir);
bool			check_textures(t_game *game);
unsigned int	*get_pxls(char *path, t_img *txtr, t_game *g);
bool			innit_txtrs(t_game *game);
int				render_full_map(t_game *g, t_img *m, t_var v);
int				put_player_full_map(t_game *game, t_img *img, double_t ratio);
void			*play_sound(void *ptr);
void			driver(void *ptr);
void			hooks(mlx_key_data_t keydata, void *param);
void			cursor_hook(double xpos, double ypos, void *param);
void			draw_txttr(mlx_image_t *img, mlx_texture_t *m, t_game *g);
mlx_texture_t	*load_txtr(char *path);
void			innit_manjal(mlx_texture_t **arr);
void			animate_manjal(t_game *game);
void			make_sound_thread(t_game *game);
void			_door_(t_game *game, bool open, t_globl_ *data);
bool			norm_rm(t_var v, t_game *g);
void			mouse_hook(mouse_key_t button, action_t action, \
modifier_key_t mods, void *param);
int				set_bool(t_game *game, bool set, bool *org);
bool			get_bool(t_game *game, bool *get);

#endif
