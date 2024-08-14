/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:06:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/14 03:59:28 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_rect(t_img *img, int x, int y_start, int y_end, int color)
{
	while (y_start < y_end && y_start < HEIGHT && y_start >= 0)
		mlx_put_pixel(img->img, x, y_start++, color);
}

int	render_ray(__rays_ *ray, t_game *game, int i)
{
	double_t	proj_dist;
	double_t	wall_h;
	double_t	ray_d;
	double_t	top;
	double_t	bott;

	ray_d = ray->distance * cos(normalize_angle(ray->angle_ray) - game->angle_view);
	proj_dist = (WIDTH / 2) / tan(FOV / 2);
	wall_h = (TILE_SIZE / ray_d) * proj_dist;
	top = (HEIGHT / 2) - (wall_h / 2);
	bott = (HEIGHT / 2) + (wall_h / 2);
	draw_rect(game->img, i, 0, top, game->ceiling.hex);
	draw_rect(game->img, i, bott, HEIGHT - 1, game->floor.hex);
	if (top < 0)
		top = 0;
	else if (top >= HEIGHT)
		top = HEIGHT - 1;
	draw_rect(game->img, i, top, bott, get_rgba(255, 255, 255, 255));
	return (1);
}
