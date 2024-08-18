/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util_II_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:41:26 by amel-has          #+#    #+#             */
/*   Updated: 2024/08/18 20:35:21 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	init_h(double_t *initX, double_t *initY, t_game *game, t_rays_ *ray)
{
	*initY = floor(game->p_pos.y / TILE_SIZE) * TILE_SIZE;
	(ray->data->facing_down) && (*initY += TILE_SIZE);
	*initX = game->p_pos.x + ((*initY - game->p_pos.y) / tan(ray->angle_ray));
}

void	step_h(double_t *stepX, double_t *stepY, t_rays_ *ray)
{
	(1) && (*stepY = TILE_SIZE, ((ray->data->facing_up) && (*stepY *= -1)));
	*stepX = TILE_SIZE / tan(ray->angle_ray);
	(ray->data->facing_left && *stepX > 0) && (*stepX *= -1);
	(ray->data->facing_right && *stepX < 0) && (*stepX *= -1);
}

void	init_v(double_t *initX, double_t *initY, t_game *game, t_rays_ *ray)
{
	*initX = floor(game->p_pos.x / TILE_SIZE) * TILE_SIZE;
	(ray->data->facing_right) && (*initX += TILE_SIZE);
	*initY = game->p_pos.y + ((*initX - game->p_pos.x) * tan(ray->angle_ray));
}

void	step_v(double_t *stepX, double_t *stepY, t_rays_ *ray)
{
	*stepX = TILE_SIZE;
	(ray->data->facing_left) && (*stepX *= -1);
	*stepY = TILE_SIZE * tan(ray->angle_ray);
	(ray->data->facing_up && *stepY > 0) && (*stepY *= -1);
	(ray->data->facing_down && *stepY < 0) && (*stepY *= -1);
}
