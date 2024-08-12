/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:56:10 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/12 07:42:34 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	red_x(t_game *game)
{
	mlx_destroy_window(game->ptr, game->win);
	g_malloc(0, FREE);
	exit(0);
	return (1);
}

int	listen_hook(int keyp, t_game *game)
{
	if (keyp == ESC)
	{
		printf("You pressed ESC\n");
		red_x(game);
	}
	else if (keyp == UP)
	{
		if (can_we_ud(game->p_pos.x, game->p_pos.y, 'u', game) != -1)
			game->p_pos.y -= SPD;
	}
	else if (keyp == DOWN)
	{
		if (can_we_ud(game->p_pos.x, game->p_pos.y, 'd', game) != -1)
			game->p_pos.y += SPD;
	}
	else if (keyp == LEFT)
	{
		if (can_we_lr(game->p_pos.x, game->p_pos.y, 'l', game) != -1)
			game->p_pos.x -= SPD;
	}
	else if (keyp == RIGHT)
	{
		if (can_we_lr(game->p_pos.x, game->p_pos.y, 'r', game) != -1)
			game->p_pos.x += SPD;
	}
	else if (keyp == R)
		game->angle_view += 0.05;
	else if (keyp == L)
		game->angle_view -= 0.05;
	return (keyp);
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
			my_mlx_pixel_put(data, x, y, color);
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
	&& (img->img = mlx_new_image(game->ptr, WIDTH, HEIGHT));
	if (!img || !img->img)
		(g_malloc(0, FREE), exit(1));
	img->addr = mlx_get_data_addr(img->img, \
	&img->bits_per_pixel, &img->line_length, &img->endian);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y <= HEIGHT / 2)
				my_mlx_pixel_put(img, x, y, game->ceiling.hex);
			else
				my_mlx_pixel_put(img, x, y, game->floor.hex);
		}
	}
	return (game->img = img, 1);
}
