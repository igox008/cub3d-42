/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:56:10 by alaassir          #+#    #+#             */
/*   Updated: 2024/07/06 06:18:34 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	return (keyp);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

int	render_map(void *ptr)
{
	t_game	*game;
	t_img	img;
	int		y;
	int		x;

	game = (t_game *)ptr;
	img.img = mlx_new_image(game->ptr, game->w * TILE_SIZE, game->h * TILE_SIZE);
	if (!img.img)
		return (1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				put_pix(x, y, BLUE, &img);
			else if (game->map[y][x] != ' ')
				put_pix(x, y, PRPL, &img);
		}
	}
	put_player(game, &img);
	mlx_put_image_to_window(game->ptr, game->win, img.img, 0, 0);
	return (1);
}
