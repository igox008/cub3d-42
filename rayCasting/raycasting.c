/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:35:42 by amel-has          #+#    #+#             */
/*   Updated: 2024/08/08 12:36:09 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double_t	horizontal_distance(t_game *game, __rays_ *ray, __globl_ *data)
{
	t_var_hor	var;

	(1) && (var.found_horz_wal_hit = 0, var.initx = 0, \
	var.inity = 0, var.stepx = 0, var.stepy = 0, ray->data = data);
	(1) && (init_h(&var.initx, &var.inity, game, ray), \
	step_h(&var.stepx, &var.stepy, ray), 0);
	(1) && (var.step_next_x = var.initx, var.step_next_y = var.inity, \
	((data->facing_up) && (var.step_next_y--)));
	while ((var.step_next_x >= 0 && var.step_next_x <= game->w * TILE_SIZE) \
		&& (var.step_next_y >= 0 && var.step_next_y <= (game->h * TILE_SIZE)))
	{
		if (has_wall_at(var.step_next_x, var.step_next_y, game))
		{
			(1) && (var.found_horz_wal_hit = 1, ray->coord_hit_h.x = \
				var.step_next_x, ray->coord_hit_h.y = var.step_next_y);
			break ;
		}
		(1) && (var.step_next_x += var.stepx, var.step_next_y += var.stepy);
	}
	if (var.found_horz_wal_hit)
		return (dis_between_to_points(game->p_pos.x, game->p_pos.y, \
			ray->coord_hit_h.x, ray->coord_hit_h.y));
	return (DBL_MAX);
}

double_t	vertical_distance(t_game *game, __rays_ *ray, __globl_ *data)
{
	t_var_hor	var;

	(1) && (var.initx = 0, var.inity = 0, var.stepx = 0, \
	var.stepy = 0, var.found_vert_wal_hit = 0, ray->data = data);
	(1) && (init_v(&var.initx, &var.inity, game, ray), \
	step_v(&var.stepx, &var.stepy, ray), 0);
	(1) && (var.step_next_x = var.initx, var.step_next_y = var.inity);
	(data->facing_left) && (var.step_next_x--);
	while ((var.step_next_x >= 0 && var.step_next_x <= game->w * TILE_SIZE) \
	&& (var.step_next_y >= 0 && var.step_next_y <= game->h * TILE_SIZE))
	{
		if (has_wall_at(var.step_next_x, var.step_next_y, game))
		{
			(1) && (var.found_vert_wal_hit = 1, ray->coord_hit_v.x \
			= var.step_next_x, ray->coord_hit_v.y = var.step_next_y);
			break ;
		}
		(1) && (var.step_next_x += var.stepx, var.step_next_y += var.stepy);
	}
	if (var.found_vert_wal_hit)
		return (dis_between_to_points(game->p_pos.x, game->p_pos.y, \
		ray->coord_hit_v.x, ray->coord_hit_v.y));
	return (DBL_MAX);
}

void	cast_ray(__rays_ *ray, t_game *game, __globl_ *data)
{
	double_t	hor_dis;
	double_t	ver_dis;

	ray_facing(ray, data);
	hor_dis = horizontal_distance(game, ray, data);
	ver_dis = vertical_distance(game, ray, data);
	if (hor_dis < ver_dis)
		(1) && (ray->coord_hit.x = ray->coord_hit_h.x, ray->coord_hit.y = \
		ray->coord_hit_h.y, ray->distance = hor_dis);
	else
		(1) && (ray->coord_hit.x = ray->coord_hit_v.x, \
		ray->coord_hit.y = ray->coord_hit_v.y, ray->distance = ver_dis);
	_daa_line(game->p_pos.x, game->p_pos.y, \
	ray->coord_hit.x, ray->coord_hit.y, game);
}

__INT32_TYPE__	cast_all_rays(t_game *game, __globl_ *data)
{
	double_t			init_angle;
	__rays_				*ray;
	__INT32_TYPE__		i;
	__INT32_TYPE__		num_rays;

	(1) && (data->angle_view = -PI / 2, i = -1, init_angle = data->angle_view \
		- (FOV / 2), num_rays = game->w * TILE_SIZE);
	ray = malloc (sizeof(__rays_));
	if (!ray)
		return (0);
	while (++i < num_rays)
		(1) &&
			(ray->angle_ray = normalize_angle(init_angle), \
			cast_ray(ray, game, data), init_angle += FOV / num_rays);
	return (free(ray), 1);
}
