/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:56:10 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/16 12:21:36 by alaassir         ###   ########.fr       */
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
		return (printf("You pressed ESC\n"), red_x(game));
	key_up_down(game);
	key_left_right(game);
	key_rl(game);
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

int	render_full_map(t_game *g, t_img *m, t_var v)
{
	double_t	ratio;

	ratio = get_ratio(g, WIDTH - 1);
	v.y = -1;
	while (g->map[++v.y / TILE_SIZE])
	{
		v.x = -1;
		while (g->map[v.y / TILE_SIZE][++v.x / TILE_SIZE])
		{
			if (g->map[v.y / TILE_SIZE][v.x / TILE_SIZE] == '1')
				mlx_put_pixel(m->img, v.x * ratio, v.y * ratio, get_rgba(0, 0, 255, 200));
			else
				mlx_put_pixel(m->img, v.x * ratio, v.y * ratio, get_rgba(0, 0, 0, 200));
		}
	}
	put_player_full_map(g, m, ratio);
	return (1);
}

int	render_map(t_game *g, t_img *m, t_var v)
{
	double_t	ratio;

	ratio = 320.0 / (TILE_SIZE * 5);
	v.y = (int)ceil(g->p_pos.y) - ((TILE_SIZE * 5) / 2);
	(1) && (v.x_i = 0, v.y_i = -1);
	while (++v.y_i < (TILE_SIZE * 5))
	{
		v.x = (int)ceil(g->p_pos.x) - ((TILE_SIZE * 5) / 2);
		v.x_i = -1;
		while (++v.x_i < (TILE_SIZE * 5))
		{
			if (v.y > 0 && v.x > 0 && v.y < g->h * TILE_SIZE && v.x < g->w * TILE_SIZE && g->map[v.y / TILE_SIZE][v.x / TILE_SIZE] == '1')
				mlx_put_pixel(m->img, v.x_i * ratio, v.y_i * ratio, get_rgba(0, 0, 255, 127));
			else
				mlx_put_pixel(m->img, v.x_i * ratio, v.y_i * ratio, get_rgba(0, 0, 0, 127));
			v.x++;	
		}
		v.y++;
	}
	put_player(g, m);
	return (1);
}
