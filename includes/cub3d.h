/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:07 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/08 08:24:33 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <stdbool.h>
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

typedef struct s___inet___ {
    double_t x;
    double_t y;
} __inet_;

typedef struct s___step___{
    double_t x;
    double_t y;
} __step_;

typedef struct s___hit___ {
    double_t x;
    double_t y;
} __hit_;

typedef struct s______globl_
{
    __INT32_TYPE__ facing_down;
    __INT32_TYPE__ facing_up ;
    __INT32_TYPE__ facing_right;
    __INT32_TYPE__ facing_left;
    double_t angle_view;
} __globl_;

typedef struct s___rays
{
    __INT32_TYPE__ index;
    double_t       distance;
    __hit_          coord_hit_h;
	__hit_          coord_hit_v;
	__hit_          coord_hit;
	double_t		angle_ray;
	__globl_		*data;
}__rays_;



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
void			ray_facing(__rays_ *ray, __globl_ *data);
void			castRay(__rays_ *ray,t_game *game,__globl_ *data);
void			_daa_line(int X0, int Y0, int X1, int Y1,t_game *game) ;
#endif
