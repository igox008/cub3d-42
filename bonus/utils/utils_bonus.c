/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:56:10 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/24 20:26:30 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	red_x(void *ptr)
{
	t_game	*game;
	int		i;

	game = (t_game *)ptr;
	set_bool(game, true, &game->stop);
	i = -1;
	while (++i <= 6)
		mlx_delete_texture(game->manjal[i]);
	mlx_delete_texture(game->manjal[13]);
	mlx_terminate(game->mlx);
	g_malloc(0, FREE);
	pthread_mutex_destroy(&game->mtx);
	exit(0);
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
	(1) && (v.r = get_ratio(g, WIDTH - 1), v.y = -1);
	(v.r > get_ratio(g, HEIGHT - 1)) && (v.r = get_ratio(g, HEIGHT - 1));
	while (g->map[++v.y / TILE_SIZE])
	{
		v.x = -1;
		while (g->map[v.y / TILE_SIZE][++v.x / TILE_SIZE])
		{
			(1) && (v.x_v = v.x * v.r, v.y_v = v.y * v.r);
			if (g->map[v.y / TILE_SIZE][v.x / TILE_SIZE] == '1' \
				&& v.x_v < WIDTH && v.y_v < HEIGHT)
				mlx_put_pixel(m->img, v.x_v, v.y_v, get_rgba(0, 0, 255, 200));
			else if (g->map[v.y / TILE_SIZE][v.x / TILE_SIZE] == 'D' \
				&& v.x_v < WIDTH && v.y_v < HEIGHT)
				mlx_put_pixel(m->img, v.x_v, v.y_v, get_rgba(128, 0, 0, 200));
			else if (g->map[v.y / TILE_SIZE][v.x / TILE_SIZE] == 'O' \
				&& v.x_v < WIDTH && v.y_v < HEIGHT)
				mlx_put_pixel(m->img, v.x_v, v.y_v, \
				get_rgba(255, 255, 255, 200));
			else if (v.x_v < WIDTH && v.y_v < HEIGHT)
				mlx_put_pixel(m->img, v.x_v, v.y_v, get_rgba(0, 0, 0, 200));
		}
	}
	put_player_full_map(g, m, v.r);
	return (1);
}

int	render_map(t_game *g, t_img *m, t_var v)
{
	(1) && (v.y_i = -1, v.r = 320.0 / (TILE_SIZE * 5), \
	v.y = ((int)ceil(g->p_pos.y) - TILE_SIZE * 5 / 2) - 1);
	while (++v.y_i < (TILE_SIZE * 5) && ++v.y >= INT_MIN)
	{
		v.x = ((int)ceil(g->p_pos.x) - TILE_SIZE * 5 / 2) - 1;
		v.x_i = -1;
		while (++v.x_i < (TILE_SIZE * 5) && ++v.x >= INT_MIN)
		{
			v.b = norm_rm(v, g);
			if (v.b && g->map[v.y / TILE_SIZE][v.x / TILE_SIZE] == '1')
				mlx_put_pixel(m->img, v.x_i * v.r, v.y_i \
				* v.r, get_rgba(0, 0, 255, 127));
			else if (v.b && g->map[v.y / TILE_SIZE][v.x / TILE_SIZE] == 'D')
				mlx_put_pixel(m->img, v.x_i * v.r, v.y_i \
				* v.r, get_rgba(128, 0, 0, 127));
			else if (v.b && g->map[v.y / TILE_SIZE][v.x / TILE_SIZE] == 'O')
				mlx_put_pixel(m->img, v.x_i * v.r, v.y_i \
				* v.r, get_rgba(255, 255, 255, 127));
			else
				mlx_put_pixel(m->img, v.x_i * v.r, v.y_i \
				* v.r, get_rgba(0, 0, 0, 127));
		}
	}
	return (put_player(g, m), 1);
}

double_t	get_ratio(t_game *game, double_t new_size)
{
	double_t	high;
	double_t	ratio;

	high = game->h;
	(game->h < game->w) && (high = game->w);
	high *= TILE_SIZE;
	ratio = new_size / high;
	return (ratio);
}
