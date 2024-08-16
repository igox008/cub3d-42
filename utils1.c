/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:01:05 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/16 06:15:57 by alaassir         ###   ########.fr       */
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

uint32_t	get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

unsigned int	*get_pxls(mlx_image_t *img)
{
	unsigned int	*pxls;
	t_var			v;

	pxls = g_malloc((TILE_SIZE * TILE_SIZE) * sizeof(uint32_t), MALLOC);
	if (!pxls)
		return (NULL);
	(1) && (v.x = 0, v.y = 0);
	while (v.y < TILE_SIZE * TILE_SIZE * 4)
	{
		pxls[v.x++] = (uint32_t)get_rgba(img->pixels[v.y], img->pixels[v.y + 1],\
		img->pixels[v.y + 2], img->pixels[v.y + 3]);
		v.y += 4;
	}
	return (pxls);
}
