/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:01:05 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/15 23:49:33 by alaassir         ###   ########.fr       */
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

	(void)game;
	(1) && (y = 320 / 2, x = 320 / 2);
	(1) && (tmp_x = x - 7, y_i = y - 7, x += 7, y += 7);
	(y_i < 0) && (y += y_i * -1, y_i = 0);
	(tmp_x < 0) && (x += tmp_x * -1, tmp_x = 0);
	while (y_i <= y && y_i < 320)
	{
		x_i = tmp_x;
		while (x_i <= x && x_i < 320)
		{
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
