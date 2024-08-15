/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:09:40 by amel-has          #+#    #+#             */
/*   Updated: 2024/08/14 23:26:31 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_up_down(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) || mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
		if (!has_wall_at(game->p_pos.x + cos(game->angle_view) \
			* SPD, game->p_pos.y + sin(game-> angle_view) * SPD, game))
		{
			game->p_pos.x += (cos(game->angle_view) * SPD);
			game->p_pos.y += (sin(game->angle_view) * SPD);
		}
	}
	else if(mlx_is_key_down(game->mlx, MLX_KEY_S) || mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		if (!has_wall_at(game->p_pos.x - cos(game->angle_view) \
			* SPD, game->p_pos.y - sin(game-> angle_view) * SPD, game))
		{
			game->p_pos.x -= (cos(game->angle_view) * SPD);
			game->p_pos.y -= (sin(game->angle_view) * SPD);
		}
	}
}

void	key_left_right(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		if (!has_wall_at(game->p_pos.x + cos(game->angle_view + M_PI / 2) \
			* SPD, game->p_pos.y + \
			sin(game-> angle_view + M_PI / 2) * SPD, game))
		{
			game->p_pos.x += (cos(game->angle_view + M_PI / 2) * SPD);
			game->p_pos.y += (sin(game->angle_view + M_PI / 2) * SPD);
		}
	}
	else if(mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		if (!has_wall_at(game->p_pos.x + cos(game->angle_view - M_PI / 2) \
			* SPD, game->p_pos.y + \
			sin(game-> angle_view - M_PI / 2) * SPD, game))
		{
			game->p_pos.x += (cos(game->angle_view - M_PI / 2) * SPD);
			game->p_pos.y += (sin(game->angle_view - M_PI / 2) * SPD);
		}
	}
}

void	key_rl(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->angle_view = fmod(game->angle_view, (2 * M_PI));
		if (game->angle_view < -M_PI)
			game->angle_view += 2 * M_PI;
		game->angle_view -= game->rotation_speed;
	}
	else if(mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->angle_view = fmod(game->angle_view, (2 * M_PI));
		if (game->angle_view > M_PI)
			game->angle_view -= 2 * M_PI;
		game->angle_view += game->rotation_speed;
	}
}