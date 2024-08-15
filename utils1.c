/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:01:05 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/15 22:30:02 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	put_player(t_game *game, t_img *img)
{
	int	x;
	int	y;
	int	x_i;
	int	y_i;
	int	tmp_x;

	(1) && (y = ((int)ceil(game->p_pos.y)) % 320, x = ((int)ceil(game->p_pos.x)) % 320);
	(1) && (tmp_x = x - 7, y_i = y - 7, x += 7, y += 7);
	(y_i < 0) && (y += y_i * -1, y_i = 0);
	(tmp_x < 0) && (x += tmp_x * -1, tmp_x = 0);
	(x > 319) && (x = 319);
	(y > 319) && (y = 319);
	while (y_i <= y && y_i < 320)
	{
		x_i = tmp_x;
		while (x_i <= x && x_i < 320)
		{
			// printf("x : %d, y : %d\n", x_i, y_i);
			mlx_put_pixel(img->img, x_i, y_i, get_rgba(0, 255, 0, 255));
			x_i++;
		}
		y_i++;
	}
	return (1);
}



int	get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int	can_we_lr(int x, int y, char dir, t_game *game)
{
	int	coef;
	int	tmp;
	int cnt;

	(0) || (coef = 1, cnt = 0);
	if (dir == 'l')
		coef = -1;
	// y -= TILE_SIZE / 2;
	while (y < (game->p_pos.y + (TILE_SIZE / 2)))
	{
		tmp = (SPD + 30) * coef;
		if (game->map[y / TILE_SIZE][(x + tmp) / TILE_SIZE] != '1')
			cnt++;
		y++;
	}
	if (cnt < TILE_SIZE / 2)
		return (-1);
	// else if (cnt < TILE_SIZE / 2 && dir == 'r')
	// 	return (right_hard_code(game), -1);
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
