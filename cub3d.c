/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:13 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/09 06:33:23 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include <time.h>

void	innit_data(t_game	*game)
{
	game->map = NULL;
	game->ea = NULL;
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	(game->floor.b = -1, game->floor.b = -1, game->floor.r = -1);
	(game->ceiling.b = -1, game->ceiling.b = -1, game->ceiling.r = -1);
	game->floor.set = false;
	game->ceiling.set = false;
	game->max_len = -1;
	game->p_cnt = 0;
}

bool	mlx_engine(t_game *game)
{
	game->ptr = mlx_init();
	if (!game->ptr)
		return (false);
	set_w_h(game);
	game->win = mlx_new_window(game->ptr, game->w * TILE_SIZE, game->h * TILE_SIZE, "Cub3D");
	if (!game->win)
		return (false);
	return (true);
}

int driver(t_game *game)
{
	render_map(game);
	cast_all_rays(game, game->data);
	mlx_put_image_to_window(game->ptr, game->win, game->img->img, 0, 0);
	mlx_destroy_image(game->ptr, game->img->img);
	return (0);
}

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
		return (g_malloc(0, FREE), 1);
	if (!mlx_engine(&game))
		return (g_malloc(0, FREE), 1);
	mlx_hook(game.win, 17, 1L << 0, red_x, &game);
	mlx_hook(game.win, 2, 1L << 0, listen_hook, &game);
	game.data = g_malloc(sizeof(__globl_), MALLOC);
	if (!game.data)
		return (1);
	mlx_loop_hook(game.ptr, driver, &game);
	mlx_loop(game.ptr);
	g_malloc(0, FREE);
	return (0);
}