/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:07 by alaassir          #+#    #+#             */
/*   Updated: 2024/07/06 06:18:22 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include "../g_col/g_collector.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include <fcntl.h>
#include "../minilibx-linux/mlx.h"

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
}   t_game;
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

#endif
