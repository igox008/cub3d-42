/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:56:10 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/13 03:34:15 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	red_x(t_game *game)
{
	// mlx_destroy_window(game->ptr, game->win);
	mlx_terminate(game->mlx);
	g_malloc(0, FREE);
	exit(0);
}

void	listen_hook(mlx_key_data_t keyp, t_game *game)
{
	if (keyp.key == MLX_KEY_ESCAPE)
	{
		printf("You pressed ESC\n");
		red_x(game);
	}
	else if (keyp.key == MLX_KEY_W)
	{
		if (can_we_ud(game->p_pos.x, game->p_pos.y, 'u', game) != -1)
			game->p_pos.y -= SPD;
	}
	else if (keyp.key == MLX_KEY_S)
	{
		if (can_we_ud(game->p_pos.x, game->p_pos.y, 'd', game) != -1)
			game->p_pos.y += SPD;
	}
	else if (keyp.key == MLX_KEY_A)
	{
		if (can_we_lr(game->p_pos.x, game->p_pos.y, 'l', game) != -1)
			game->p_pos.x -= SPD;
	}
	else if (keyp.key == MLX_KEY_D)
	{
		if (can_we_lr(game->p_pos.x, game->p_pos.y, 'r', game) != -1)
			game->p_pos.x += SPD;
	}
	else if (keyp.key == MLX_KEY_RIGHT)
		game->angle_view += 0.05;
	else if (keyp.key == MLX_KEY_LEFT)
		game->angle_view -= 0.05;
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
	*(unsigned int*)dst = color;
}

void	put_pix(int x_idx, int y_idx, int color, t_img *data, double_t ratio)
{
	int	y;
	int	x;
	int	scaled_tile_size;

	scaled_tile_size = TILE_SIZE * ratio;
	y = y_idx * scaled_tile_size;
	while (y < (y_idx + 1) * scaled_tile_size)
	{
		x = x_idx * scaled_tile_size;
		while (x < (x_idx + 1) * scaled_tile_size)
		{
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

int	render_map(t_game *game, t_img *img)
{
	int		y;
	int		x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				put_pix(x, y, BLUE, img, game->ratio);
			else
				put_pix(x, y, 0x0000, img, game->ratio);
		}
	}
	return (1);
}

int	render_game(t_game *game)
{
	t_img	*img; 
	int		y;
	int		x;

	((img = malloc(sizeof(t_img))) && img) \
	&& (img->img = mlx_new_image(game->mlx, WIDTH, HEIGHT));
	if (!img || !img->img)
		(g_malloc(0, FREE), exit(1));
	return (game->img = img, 1);
}
