/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:05:24 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 19:54:28 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	driver(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	listen_hook(ptr);
	cast_all_rays(game, game->data);
}

void	listen_hook(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		return (printf("You pressed ESC\n"), red_x(game));
	key_up_down(game);
	key_left_right(game);
	key_rl(game);
}
