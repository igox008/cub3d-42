/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:05:24 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/17 07:00:35 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cursor_hook(double xpos, double ypos, void* param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)ypos;
	if (!game->full_map && game->v.mode == MLX_MOUSE_HIDDEN)
	{
		game->angle_view += ((xpos - WIDTH/2) * (M_PI / 180)) * 0.1;
		mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	}
}

void	hooks(mlx_key_data_t keydata, void* param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)keydata;
	// if (mlx_is_key_down(game->mlx, MLX_KEY_TAB) && !game->full_map)
	if (mlx_is_key_down(game->mlx, MLX_KEY_TAB) && !game->full_map)
		game->full_map = true;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_TAB) && game->full_map)
	{
		clear_img(game->mini_map->img);
		game->full_map = false;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_SPACE) && !game->hayad)
		(1) && (pthread_mutex_lock(&game->mtx), game->allo = true,\
		pthread_mutex_unlock(&game->mtx), game->hayad = true);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_C))
	{
		if (game->v.mode == MLX_MOUSE_HIDDEN)
			game->v.mode = MLX_MOUSE_NORMAL;
		else
			game->v.mode = MLX_MOUSE_HIDDEN;
		mlx_set_cursor_mode(game->mlx, game->v.mode);
	}
}

void	driver(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	listen_hook(ptr);
	if (game->full_map)
		render_full_map(game, game->mini_map, game->v);
	else
		render_map(game, game->mini_map, game->v);
	if (game->hayad)
		animate_manjal(game);
	cast_all_rays(game, game->data);
}

void	listen_hook(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		return (printf("You pressed ESC\n"), red_x(game));
	if (game->full_map)
		return ;
	key_up_down(game);
	key_left_right(game);
	key_rl(game);
}
