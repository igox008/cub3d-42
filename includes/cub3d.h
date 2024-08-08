/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:07 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/08 12:35:02 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#include <unistd.h>
#include <limits.h>
#include "../g_col/g_collector.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include <fcntl.h>
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <math.h>
# define EPS_IN_IFIC (SIGCHLD * (0x00008 + SIG_BLOCK ))
# include <signal.h>
# include <stdint.h>
# define FOV 60 * M_PI / 180

typedef struct s___point___ 
{
    double_t x;
    double_t y;
} __point_;

typedef struct s______globl_
{
    __INT32_TYPE__	facing_down;
    __INT32_TYPE__	facing_up;
    __INT32_TYPE__	facing_right;
    __INT32_TYPE__	facing_left;
    double_t		angle_view;
} __globl_;

typedef struct s___rays
{
    __INT32_TYPE__	index;
    double_t		distance;
    __point_		coord_hit_h;
	__point_		coord_hit_v;
	__point_		coord_hit;
	double_t		angle_ray;
	__globl_		*data;
} __rays_;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
	bool	set;
}   t_rgb;

typedef struct s_corr
{
	int	x;
	int	y;
}	t_corr;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct  s_game
{
	char    **map;
	char    *so;
	char    *no;
	char    *we;
	char    *ea;
	t_rgb   floor;
	t_rgb   ceiling;
	int		max_len;
	int		p_cnt;
	char	*last;
	void	*ptr;
	void	*win;
	int		h;
	int		w;
	t_corr	p_pos;
	t_img	*img;
}   t_game;

typedef struct s__General
{
		__globl_ *global;
		__rays_		*ray;
		t_game		*game;
		t_img		*img;
}t_General;

typedef struct s_var_hor{
	__INT32_TYPE__	found_horz_wal_hit;
	__INT32_TYPE__	found_vert_wal_hit;
	double_t		inity;
	double_t		initx;
	double_t		stepy;
	double_t		stepx;
	double_t		step_next_x;
	double_t		step_next_y;
} t_var_hor;

# define ESC 53
# define UP 13
# define RIGHT 2
# define LEFT 0
# define DOWN 1
# define TILE_SIZE 64
# define SPD 4
# define PI 3.1415927
# define PRPL 0x800080
# define BLUE 0x0000FF
# define GRAY 0x808080
t_img	img;
bool	parcing(char *file, t_game *game);
char	*till_char(char *line);
bool	ft_isspace(char c);
bool	is_rgb(char *line);
bool	parse_rgb(char **arr, char *line, t_rgb *rgb);
bool	is_valid_rgb(int rgb, char *s);
bool	check_assets(t_game *game);
bool	final_map(t_game *game, char *last, int fd);
bool	last_first(char *s);
bool	mdl_line(char *s);
bool	final_check(char **map);
void	set_w_h(t_game *game);
int		listen_hook(int keyp, t_game *game);
int		red_x(t_game *game);
int		render_map(void *ptr);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		put_player(t_game *game, t_img *img);
int		can_we_lr(int x, int y, char dir, t_game *game);
int		can_we_ud(int x, int y, char dir, t_game *game);


__INT32_TYPE__	cast_all_rays(t_game *game, __globl_ *data);
double_t		dis_between_to_points(double_t xa, double_t ya, double_t xb, double_t yb);
void			ray_facing(__rays_ *ray, __globl_ *data);
double_t		normalize_angle(double angle);
bool			has_wall_at(double_t i, double_t j, t_game *game);
void			init_h(double_t *initX,double_t *initY,t_game *game, __rays_ *ray);
void			step_h(double_t *stepX, double_t *stepY ,__rays_ *ray);
void			init_v(double_t *initX,double_t *initY,t_game *game, __rays_ *ray);
void			step_v(double_t *stepX, double_t *stepY ,__rays_ *ray);
void			_daa_line(int X0, int Y0, int X1, int Y1,t_game *game) ;
#endif
