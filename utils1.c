/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:01:05 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/09 03:10:24 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	put_player(t_game *game, t_img *img)
{
	int	x;
	int	y;

	y = (game->p_pos.y - 32) + 8;
	while (y < (game->p_pos.y - 32) + 48)
	{
		x = (game->p_pos.x - 32) + 8;
		while (x < (game->p_pos.x - 32) + 48)
		{
			my_mlx_pixel_put(img, x, y, GRAY);
			x++;
		}
		y++;
	}
	return (1);
}

int	right_hard_code(t_game *game)
{
	int	i;

	i = -1;
	while (++i <= 4)
	{
		if (game->map[game->p_pos.y / TILE_SIZE][(game->p_pos.x + 1) / TILE_SIZE] != '1')
			game->p_pos.x++;
	}
	return (1);
}

int	can_we_lr(int x, int y, char dir, t_game *game)
{
	int	coef;
	int	tmp;
	int cnt;

	(0) || (coef = 1, cnt = 0);
	if (dir == 'l')
		coef = -1;
	y -= TILE_SIZE / 2;
	while (y < (game->p_pos.y + (TILE_SIZE / 2)))
	{
		tmp = SPD * coef;
		if (game->map[y / TILE_SIZE][(x + tmp) / TILE_SIZE] != '1')
			cnt++;
		y++;
	}
	if (cnt < TILE_SIZE / 2 && dir == 'l')
		return (-1);
	else if (cnt < TILE_SIZE / 2 && dir == 'r')
		return (right_hard_code(game), -1);
	return (y);
}

int	can_we_ud(int x, int y, char dir, t_game *game)
{
	int	coef;
	int	tmp;
	int	cnt;

	(0) || (coef = 1, cnt = 0);
	if (dir == 'u')
		coef = -1;
	x -= TILE_SIZE / 2;
	while (x < (game->p_pos.x + (TILE_SIZE / 2)))
	{
		tmp = SPD * coef;
		if (game->map[(y + tmp) / TILE_SIZE][x / TILE_SIZE] != '1')
			cnt++;
		x++;
	}
	if (cnt < TILE_SIZE / 2)
		return (-1);
	return (x);
}
