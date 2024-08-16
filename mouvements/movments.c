/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:09:40 by amel-has          #+#    #+#             */
/*   Updated: 2024/08/16 06:46:49 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_wall(int x, int y, t_game *game)
{
	int	tmp_x;
	int	tmp_y;
	int	tmp_x_1 ;
	int	tmp_y_1 ;

	tmp_x = (x + 30) / TILE_SIZE;
	tmp_y = (y + 30) / TILE_SIZE;
	tmp_x_1 = (x - 30) / TILE_SIZE;
	tmp_y_1 = (y - 30) / TILE_SIZE;
	x /= TILE_SIZE;
	y /= TILE_SIZE;
	if ((x >= game->w || y >= game->h || x < 0 || y < 0)
		|| (tmp_x >= game->w || tmp_y >= game->h 
			|| tmp_x < 0 || tmp_y < 0 || tmp_x_1 < 0 || tmp_y_1 < 0 || tmp_x_1 >= game->w || tmp_y_1 >= game->h))
		return (1);
	if (game->map[y][x] == '1' 
		|| game->map[tmp_y][tmp_x] == '1'
		|| game->map[tmp_y][x] == '1'
		|| game->map[y][tmp_x] == '1'
		|| game->map[tmp_y_1][tmp_x] == '1'
		|| game->map[tmp_y][tmp_x_1] == '1')
		return (1);
	return (0);
}

void  key_up_down(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) || mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
		if (!check_wall(game->p_pos.x + cos(game->angle_view) \
			* SPD, game->p_pos.y + sin(game-> angle_view) * SPD, game))
		{
			game->p_pos.x += (cos(game->angle_view) * SPD);
			game->p_pos.y += (sin(game->angle_view) * SPD);
		}
	}
	else if(mlx_is_key_down(game->mlx, MLX_KEY_S) || mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		if (!check_wall(game->p_pos.x - cos(game->angle_view) \
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
		if (!check_wall(game->p_pos.x + cos(game->angle_view + M_PI / 2) \
			* SPD, game->p_pos.y + \
			sin(game-> angle_view + M_PI / 2) * SPD, game))
		{
			game->p_pos.x += (cos(game->angle_view + M_PI / 2) * SPD);
			game->p_pos.y += (sin(game->angle_view + M_PI / 2) * SPD);
		}
	}
	else if(mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		if (!check_wall(game->p_pos.x + cos(game->angle_view - M_PI / 2) \
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