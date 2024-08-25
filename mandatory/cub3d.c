/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:13 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/24 20:15:57 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	innit_data(&game);
	if (ac != 2)
		return (ft_putendl_fd("ERROR", 2), 1);
	if (!parcing(av[1], &game))
		return (g_malloc(0, FREE), g_malloc(0, FREE_S), 1);
	if (!mlx_engine(&game))
		return (g_malloc(0, FREE), 1);
	game.data = g_malloc(sizeof(t_globl_), MALLOC);
	if (!game.data)
		return (1);
	mlx_close_hook(game.mlx, red_x, (void *)&game);
	mlx_loop_hook(game.mlx, driver, (void *)&game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (g_malloc(0, FREE), 0);
}
