/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util_I.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:01:55 by amel-has          #+#    #+#             */
/*   Updated: 2024/08/18 16:42:31 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double_t	dis_between_to_points(double_t xa, double_t ya, \
	double_t xb, double_t yb)
{
	return (sqrt(pow((xb - xa), 2) + pow((yb - ya), 2)));
}

void	ray_facing(t_rays_ *ray, t_globl_ *data)
{
	data->facing_down = ray->angle_ray > 0 && ray->angle_ray < M_PI;
	data->facing_up = !data->facing_down;
	data->facing_right = \
	ray->angle_ray < 0.5 * M_PI || ray->angle_ray > 1.5 * M_PI;
	data->facing_left = !data->facing_right;
}

double_t	normalize_angle(double angle)
{
	(angle > 0) && (angle -= 2 * M_PI, (angle <= 0) && (angle += 2 * M_PI));
	(angle < 0) && (angle += 2 * M_PI, (angle <= 0) && (angle -= 2 * M_PI));
	return (angle);
}

bool	has_wall_at_v(double_t i, double_t j, t_game *game, t_rays_ *ray)
{
	int	x;
	int	y;

	if (i < 0 || i > (game->w * TILE_SIZE) \
	|| j < 0 || j > (game->h * TILE_SIZE))
		return (1);
	x = floor(i / TILE_SIZE);
	y = floor(j / TILE_SIZE);
	if (game->map && game->map[y] && \
		game->map[y][x] && (game->map[y][x] == '1'))
		return (ray->hit_door_v = false, true);
	else if (game->map && game->map[y] \
		&& game->map[y][x] && game->map[y][x] == 'D')
		return (ray->hit_door_v = true, true);
	return (false);
}

bool	has_wall_at_h(double_t i, double_t j, t_game *game, t_rays_ *ray)
{
	int	x;
	int	y;

	if (i < 0 || i > (game->w * TILE_SIZE) \
	|| j < 0 || j > (game->h * TILE_SIZE))
		return (1);
	x = floor(i / TILE_SIZE);
	y = floor(j / TILE_SIZE);
	if (game->map && game->map[y] \
		&& game->map[y][x] && (game->map[y][x] == '1'))
		return (ray->hit_door_h = false, true);
	else if (game->map && game->map[y] \
		&& game->map[y][x] && game->map[y][x] == 'D')
		return (ray->hit_door_h = true, true);
	return (false);
}
