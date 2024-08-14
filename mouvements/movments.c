/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:09:40 by amel-has          #+#    #+#             */
/*   Updated: 2024/08/14 04:01:29 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_up_down(t_game *game, int key)
{
	if (key == UP)
	{
		if (!has_wall_at(game->p_pos.x + cos(game->angle_view) \
			* SPD, game->p_pos.y + sin(game-> angle_view) * SPD, game))
		{
			game->p_pos.x += (cos(game->angle_view) * SPD);
			game->p_pos.y += (sin(game->angle_view) * SPD);
		}
	}
	else
	{
		if (!has_wall_at(game->p_pos.x - cos(game->angle_view) \
			* SPD, game->p_pos.y - sin(game-> angle_view) * SPD, game))
		{
			game->p_pos.x -= (cos(game->angle_view) * SPD);
			game->p_pos.y -= (sin(game->angle_view) * SPD);
		}
	}
}

void	key_left_right(t_game *game, int key)
{
	if (key == RIGHT)
	{
		if (!has_wall_at(game->p_pos.x + cos(game->angle_view + M_PI / 2) \
			* SPD, game->p_pos.y + \
			sin(game-> angle_view + M_PI / 2) * SPD, game))
		{
			game->p_pos.x += (cos(game->angle_view + M_PI / 2) * SPD);
			game->p_pos.y += (sin(game->angle_view + M_PI / 2) * SPD);
		}
	}
	else
	{
		if (!has_wall_at(game->p_pos.x + cos(game->angle_view - M_PI / 2) \
			* SPD, game->p_pos.y + \
			sin(game-> angle_view - M_PI / 2) * SPD, game))
		{
			game->p_pos.x += (cos(game->angle_view - M_PI / 2) * SPD);
			game->p_pos.y += (sin(game->angle_view - M_PI / 2) * SPD);
			// printf("{%f} == {%f}\n",game->p_pos.y,game->p_pos.y + (sin(game->angle_view - M_PI / 2) * SPD));
		}
	}
}

void	key_rl(t_game *game, int key)
{
	if (key == L)
	{
		// printf("{%f} == ",game->angle_view * 180 / M_PI);
		// if (game->angle_view < -M_PI)
		// {
		// 	// printf("\nyes{%f}",game->angle_view * 180 / M_PI);
		// 	game->angle_view += 2 * M_PI;
		// 	// printf("{%f}\n",game->angle_view * 180 / M_PI);
		// }
		// printf("{%f}\n",game->angle_view * 180 / M_PI);
		game->angle_view -= game->rotation_speed;
		game->angle_view = fmod(game->angle_view, (2 * M_PI));
	}
	else
	{
		// printf("{%f} == ", game->angle_view * 180 / M_PI);
		// printf("{%f}\n", game->angle_view * 180 / M_PI);
		game->angle_view += game->rotation_speed;
		game->angle_view = fmod(game->angle_view, (2 * M_PI));
	}
}

// int	listen_hook(int keyp, t_game *game)
// {
// 	if (keyp == ESC)
// 		(1) && (printf("You pressed ESC\n"), red_x(game), 0);
// 	else if (keyp == UP || keyp == DOWN)
// 		key_up_down(game, keyp);
// 	else if (keyp == RIGHT || keyp == LEFT)
// 		key_left_right(game, keyp);
// 	else if (keyp == R || keyp == L)
// 		key_rl(game, keyp);
// 	return (keyp);
// }
