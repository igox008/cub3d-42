/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:13 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/19 10:48:52 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_game	game;

	innit_data(&game);
	if (ac != 2)
		return (ft_putendl_fd("ERROR", 2), 1);
	if (!parcing(av[1], &game))
		return (g_malloc(0, FREE), g_malloc(0, FREE_S), 1);
	innit_manjal(game.manjal);
	if (!mlx_engine(&game))
		return (g_malloc(0, FREE), 1);
	make_sound_thread(&game);
	game.data = g_malloc(sizeof(t_globl_), MALLOC);
	if (!game.data)
		return (1);
	mlx_close_hook(game.mlx, red_x, (void *)&game);
	mlx_loop_hook(game.mlx, driver, (void *)&game);
	mlx_set_cursor_mode(game.mlx, game.v.mode);
	mlx_cursor_hook(game.mlx, cursor_hook, (void *)&game);
	mlx_key_hook(game.mlx, hooks, (void *)&game);
	mlx_mouse_hook(game.mlx, mouse_hook, (void *)&game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (g_malloc(0, FREE), 0);
}
