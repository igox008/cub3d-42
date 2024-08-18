/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:06:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 16:41:38 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_rect(t_img *img, t_var v, int color)
{
	while (v.y_i < v.y && v.y_i < HEIGHT && v.y_i >= 0)
		mlx_put_pixel(img->img, v.x, v.y_i++, color);
}

t_img	get_img(t_game *game, t_rays_	*ray)
{
	if ((ray->is_vert && ray->hit_door_v) || (!ray->is_vert && ray->hit_door_h))
		return (game->door);
	if (ray->is_vert)
	{
		if (cos(ray->angle_ray) < 0)
			return (game->i_ea);
		return (game->i_so);
	}
	else
	{
		if (sin(ray->angle_ray) < 0)
			return (game->i_no);
		return (game->i_we);
	}
}

void	draw_texture(t_game *g, int x, int y_start, int y_end)
{
	t_var		v;
	t_rays_		*ray;
	uint32_t	color_idx;

	ray = g->ray;
	if (ray->is_vert)
		v.offst_x = ((int)ray->coord_hit.y) % TILE_SIZE;
	else
		v.offst_x = ((int)ray->coord_hit.x) % TILE_SIZE;
	v.y = y_start;
	while (v.y < y_end && v.y < HEIGHT && v.y >= 0)
	{
		v.y_v = (v.y + (g->wall_h / 2) - (HEIGHT / 2));
		v.offst_y = v.y_v * ((double_t)TILE_SIZE / g->wall_h);
		color_idx = (int)(TILE_SIZE * v.offst_y) + v.offst_x;
		mlx_put_pixel(g->img->img, x, v.y, get_img(g, ray).pxls[color_idx]);
		v.y++;
	}
}

int	render_ray(t_rays_ *ray, t_game *game, int i)
{
	double_t	proj_dist;
	double_t	wall_h;
	double_t	ray_d;
	double_t	top;
	double_t	bott;

	ray_d = ray->distance * \
	cos(normalize_angle(ray->angle_ray) - game->angle_view);
	proj_dist = (WIDTH / 2) / tan(FOV / 2);
	wall_h = (TILE_SIZE / ray_d) * proj_dist;
	top = (HEIGHT / 2) - (wall_h / 2);
	bott = (HEIGHT / 2) + (wall_h / 2);
	game->ray = ray;
	game->wall_h = wall_h;
	draw_rect(game->img, (t_var){.x = i, \
	.y_i = 0, .y = top}, game->ceiling.hex);
	draw_rect(game->img, (t_var){.x = i, \
	.y_i = bott, .y = HEIGHT - 1}, game->floor.hex);
	if (top < 0)
		top = 0;
	else if (top >= HEIGHT)
		top = HEIGHT - 1;
	draw_texture(game, i, top, bott);
	return (1);
}
