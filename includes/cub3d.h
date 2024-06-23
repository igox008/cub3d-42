/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:07 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/23 08:59:52 by alaassir         ###   ########.fr       */
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

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
	bool	set;
}   t_rgb;

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
}   t_game;

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

#endif
