/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:06:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/12 07:25:25 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_rect(t_game *game, int x, int y, int w, int h, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < h && i + y < HEIGHT)
	{
		j = -1;
		while (++j < w && j < WIDTH)
			my_mlx_pixel_put(game->img, x + j, y + i, color);
	}
}

int	render_ray(__rays_ *ray, t_game *game, int i)
{
	double_t	proj_dist;
	double_t	wall_h;
	// t_corr		pos;

	proj_dist = (WIDTH / 2) / tan(FOV / 2);
	wall_h = (TILE_SIZE / ray->distance ) * proj_dist;
	// pos.x = i;
	// pos.y = (HEIGHT / 2) - (wall_h / 2);
	double_t tmp = (HEIGHT / 2) - (wall_h / 2);
	if (tmp < 0)
		tmp = (int)tmp * -1;
	draw_rect(game, i, tmp, 1, wall_h, 0xFFFFFF);
	return (1);
}
