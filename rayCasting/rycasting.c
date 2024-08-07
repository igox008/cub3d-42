/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rycasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:29:21 by amel-has          #+#    #+#             */
/*   Updated: 2024/08/07 17:58:59 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

double_t	dis_betweenTopoints(double_t xa, double_t ya, double_t xb, double_t yb)
{
	return (sqrt((xb - xa)*((xb - xa)) + (yb - ya) * (yb - ya)));
}

void	ray_facing(__rays_ *ray, __globl_ *data)
{
	data->facing_down = ray->angle_ray > 0 && ray->angle_ray < M_PI;
	data->facing_up = !data->facing_down;
	data->facing_right = ray->angle_ray < 0.5 * M_PI || ray->angle_ray > 1.5 * M_PI;
	data->facing_left = !data->facing_right;
}

double_t	normalizeAngle(double angle) {
	angle = fmod(angle , (2 * M_PI));
	if (angle < 0) {
		angle = (2 * M_PI) + angle;
	}
	// (angle > 0) && (angle -= 2 * M_PI , (angle < 0) && (angle += 2 * M_PI));
	// (angle < 0) && (angle += 2 * M_PI ,  (angle < 0) && (angle -= 2 * M_PI));
	return angle;
}

bool	hasWallAt(double_t i, double_t j, t_game *game)
{
	if (i < 0 || i > (game->w * TILE_SIZE) || j < 0 || j > (game->h * TILE_SIZE))
		return (1);
	int x = floor(i / TILE_SIZE);
	int y = floor(j / TILE_SIZE);
	return (game->map[y][x] == '1');
}

double_t	horizontal_distance (t_game *game, __rays_ *ray,__globl_ *data)
{
	__INT32_TYPE__	foundHorzWalHit;
	double_t		initY;
	double_t		initX;
	double_t		stepY;
	double_t		stepX;
	double_t		step_next_x;
	double_t		step_next_y;

	(1) && (foundHorzWalHit = 0, initX = 0, initY = 0, stepX = 0, stepX = 0);
	initY = floor(game->p_pos.y / TILE_SIZE) * TILE_SIZE;
	initY += data->facing_down ? TILE_SIZE : 0;
	initX = game->p_pos.x + ((initY - game->p_pos.y) / tan(ray->angle_ray));
	stepY = TILE_SIZE;
	(data->facing_up) && (stepY *= -1);
	stepX = TILE_SIZE / tan(ray->angle_ray);
	stepX *= data->facing_left && stepX > 0 ? -1 : 1;
	stepX *= data->facing_right && stepX < 0 ? -1 : 1;
	step_next_x = initX;
	step_next_y = initY;
	(data->facing_up)	&& (step_next_y--);
	while ((step_next_x >= 0 &&  step_next_x <= game->w * TILE_SIZE) && (step_next_y >= 0 && step_next_y <= (game->h * TILE_SIZE)))
	{
		if (hasWallAt(step_next_x, step_next_y ,game))
		{
			foundHorzWalHit = 1;
			ray->coord_hit_h.x = step_next_x;
			ray->coord_hit_h.y = step_next_y;
			// _daa_line(game->p_pos.x, game->p_pos.y, ray->coord_hit_h.x, ray->coord_hit_h.y, game);
			break;
		}
		step_next_x += stepX;
		step_next_y += stepY;
	}
	if (foundHorzWalHit)
		return (dis_betweenTopoints(game->p_pos.x, game->p_pos.y, ray->coord_hit_h.x, ray->coord_hit_h.y));
	return (INT_MAX);
}

double_t	vertical_distance (t_game *game, __rays_ *ray,__globl_ *data)
{
	__INT32_TYPE__	foundVertWalHit;
	double_t		initY;
	double_t		initX;
	double_t		stepY;
	double_t		stepX;
	double_t		step_next_x;
	double_t		step_next_y;

	(1) && (initX = 0, initY = 0, stepX = 0, stepY = 0, foundVertWalHit = 0);
	initX = floor(game->p_pos.x / TILE_SIZE) * TILE_SIZE;
	initX += data->facing_right ? TILE_SIZE : 0;
	initY = game->p_pos.y + ((initX - game->p_pos.x) * tan(ray->angle_ray));
	stepX = TILE_SIZE;
	stepX *= data->facing_left ? -1 : 1;
	stepY = TILE_SIZE * tan(ray->angle_ray);
	stepY *= (data->facing_up && stepY > 0) ? -1 : 1;
	stepY *= (data->facing_down && stepY < 0) ? -1 : 1;
	step_next_x = initX;
	step_next_y = initY;
	(data->facing_left)	&& (step_next_x--);
	while ((step_next_x >= 0 &&  step_next_x <= game->w * TILE_SIZE) && (step_next_y >= 0 && step_next_y <= game->h * TILE_SIZE))
	{
		if (hasWallAt(step_next_x,step_next_y, game))
		{
			(1) && (foundVertWalHit = 1, ray->coord_hit_v.x = step_next_x, ray->coord_hit_v.y = step_next_y);
			break ;
		}
		(1) && (step_next_x += stepX, step_next_y += stepY);
	}
	if (foundVertWalHit)
		return (dis_betweenTopoints(game->p_pos.x, game->p_pos.y, ray->coord_hit_v.x, ray->coord_hit_v.y));
	return (INT_MAX);
}

void	castRay(__rays_ *ray,t_game *game,__globl_ *data)
{
	double_t	hor_dis;
	double_t	ver_dis;

	ray_facing(ray, data);
	hor_dis = horizontal_distance(game, ray, data);
	ver_dis = vertical_distance(game, ray,data);
	if (hor_dis < ver_dis)
		(1) && (ray->coord_hit.x = ray->coord_hit_h.x, ray->coord_hit.y = ray->coord_hit_h.y, ray->distance = hor_dis);
	else
		(1) && (ray->coord_hit.x = ray->coord_hit_v.x, ray->coord_hit.y = ray->coord_hit_v.y, ray->distance= ver_dis);
	_daa_line(game->p_pos.x, game->p_pos.y, ray->coord_hit.x, ray->coord_hit.y, game);
}

void	cast_all_rays(t_game *game, __globl_ *data)
{
	double_t			initAngle;
	__rays_				*ray;
	__INT32_TYPE__		i;
	__INT32_TYPE__		num_rays;

	data->angle_view =  -PI / 2;
	(1) && (i = -1, initAngle = data->angle_view - (FOV / 2));
	num_rays = game->w * TILE_SIZE;
	ray = malloc (sizeof(__rays_));
	while (++i < num_rays)
		(1) &&
			(ray->angle_ray = normalizeAngle(initAngle), castRay(ray, game, data), initAngle += FOV / num_rays);
}
