/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:13 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/17 04:47:11 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	v()
{
	system("leaks cub3d");
}

int	main(int ac, char **av)
{
	t_game	game;

	// atexit(v);
	innit_data(&game);
	if (ac != 2)
		return (ft_putendl_fd("ERROR", 2), 1);
	if (!parcing(av[1], &game))
		return (g_malloc(0, FREE), g_malloc(0, FREE_S), 1);
	if (!mlx_engine(&game))
		return (g_malloc(0, FREE), 1);
	game.data = g_malloc(sizeof(__globl_), MALLOC);
	if (!game.data)
		return (1);
	game.ratio = 0.5;
	mlx_close_hook(game.mlx, red_x, (void *)&game);
	mlx_loop_hook(game.mlx, driver, (void *)&game);
	mlx_set_cursor_mode(game.mlx, game.v.mode);
	mlx_cursor_hook(game.mlx, cursor_hook, (void *)&game);
	mlx_key_hook(game.mlx, hooks, (void *)&game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (g_malloc(0, FREE), 0);
}