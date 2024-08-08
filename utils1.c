/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:01:05 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/08 14:19:05 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	put_player(t_game *game, t_img *img)
{
	int	x;
	int	y;

	y = game->p_pos.y + 4;
	while (y < game->p_pos.y + 16)
	{
		x = game->p_pos.x + 4;
		while (x < game->p_pos.x + 16)
		{
			my_mlx_pixel_put(img, x, y, GRAY);
			x++;
		}
		y++;
	}
	return (1);
}

int	can_we_lr(int x, int y, char dir, t_game *game)
{
	int	coef;
	int	tmp;

	coef = 1;
	if (dir == 'l')
		coef = -1;
	y += 4;
	while (y < (game->p_pos.y + TILE_SIZE) - 4)
	{
		tmp = 2 * coef;
		(dir == 'r') && (tmp += TILE_SIZE);
		if (game->map[y / TILE_SIZE][(x + tmp) / TILE_SIZE] == '1')
		{
			y = -1;
			break ;
		}
		y++;
	}
	return (y);
}

int	can_we_ud(int x, int y, char dir, t_game *game)
{
	int	coef;
	int	tmp;

	coef = 1;
	if (dir == 'u')
		coef = -1;
	x += 4;
	while (x < (game->p_pos.x + TILE_SIZE) - 4)
	{
		tmp = 2 * coef;
		(dir == 'd') && (tmp += TILE_SIZE);
		if (game->map[(y + tmp) / TILE_SIZE][x / TILE_SIZE] == '1')
		{
			x = -1;
			break ;
		}
		x++;
	}
	return (x);
}
