/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:56:10 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/15 22:39:05 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	red_x(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	mlx_terminate(game->mlx);
	g_malloc(0, FREE);
	exit(0);
}

void	listen_hook(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		printf("You pressed ESC\n");
		red_x(game);
	}
	key_up_down(game);
	key_left_right(game);
	key_rl(game);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (!data)
	{
		printf("error: mymlx");
		exit(1);
	}
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	put_pix(int x_idx, int y_idx, int color, t_img *data)
{
	int	y;
	int	x;

	y = y_idx * TILE_SIZE;
	while (y < (y_idx + 1) * TILE_SIZE)
	{
		x = x_idx * TILE_SIZE;
		while (x < (x_idx + 1) * TILE_SIZE)
		{
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

int	render_map(t_game *g, t_img *m, t_var v)
{
	v.y = (int)ceil(g->p_pos.y) - 160;
	(v.y < 0) && (v.y = 0);
	(1) && (v.x_i = 0, v.y_i = -1);
	while (++v.y_i < 320)
	{
		v.x = (int)ceil(g->p_pos.x) - 160;
		(v.x < 0) && (v.x = 0);
		v.x_i = -1;
		while (++v.x_i < 320)
		{
			if (g->map[v.y / TILE_SIZE][v.x / TILE_SIZE] == '1')
				mlx_put_pixel(m->img, v.x_i, v.y_i, get_rgba(0, 0, 255, 255));
			else
				mlx_put_pixel(m->img, v.x_i, v.y_i, get_rgba(0, 0, 0, 255));
			v.x++;	
		}
		v.y++;
	}
	// put_player(g, m);
	return (1);
}
// int	render_map(t_game *g, t_img *m, t_var v)
// {
// 	(1) && (v.y = -1, v.y_p = 0, v.y_i = 2, v.y_v = -2);
// 	(((int)g->p_pos.y / TILE_SIZE) - 2 < 0) && (v.y_i = 1, v.y_v = -3);
// 	while (g->map[++v.y])
// 	{
// 		(1) && (v.x = -1, v.x_p = 0);
// 		(((int)g->p_pos.x / TILE_SIZE) - 2 < 0) && (v.x_i = 1, v.x_v = -3);
// 		(((int)g->p_pos.x / TILE_SIZE) - 2 >= 0) && (v.x_i = 2, v.x_v = -2);
// 		if (v.y + v.y_i == (int)g->p_pos.y / TILE_SIZE && v.y_i >= v.y_v)
// 		{
// 			while (g->map[v.y][++v.x])
// 			{
// 				if (v.x + v.x_i == (int)g->p_pos.x / TILE_SIZE
// 					&& v.x_i >= v.x_v)
// 				{
// 					if (g->map[v.y][v.x] == '1')
// 						put_pix(v.x_p, v.y_p, get_rgba(0, 0, 255, 255), m);
// 					else
// 						put_pix(v.x_p, v.y_p, get_rgba(0, 0, 0, 255), m);
// 					(1) && (v.x_p++, v.x_i--);
// 				}
// 			}
// 			(1) && (v.y_p++, v.y_i--);
// 		}
// 	}
// 	return (put_player(g, m), 1);
// }
