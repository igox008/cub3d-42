/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:13 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/12 07:49:31 by alaassir         ###   ########.fr       */
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

void	set_ratio(t_game *game)
{
	double_t	high;

	((high = game->h) && game->h < game->w) && (high = game->w);
	high *= TILE_SIZE;
	game->ratio = 400.0 / high;
}

bool	mlx_engine(t_game *game)
{
	game->ptr = mlx_init();
	if (!game->ptr)
		return (false);
	set_w_h(game);
	game->win = mlx_new_window(game->ptr, WIDTH, HEIGHT, "Cub3D");
	if (!game->win)
		return (false);
	return (true);
}

int driver(t_game *game)
{
	t_img	*rays;

	rays = malloc(sizeof(t_img));
	if (!rays)
		return (g_malloc(0, FREE), exit(0), 0);
	rays->img = mlx_new_image(game->ptr, (game->w * TILE_SIZE) * game->ratio, (game->h * TILE_SIZE) * game->ratio);
	if (!rays->img)
		return (g_malloc(0, FREE), exit(0), 0);
	rays->addr = mlx_get_data_addr(rays->img, &rays->bits_per_pixel, &rays->line_length, &rays->endian);
	game->rays = rays;
	render_game(game);
	render_map(game, rays);
	cast_all_rays(game, game->data);
	mlx_put_image_to_window(game->ptr, game->win, game->img->img, 0, 0);
	mlx_put_image_to_window(game->ptr, game->win, rays->img, 0, 0);
	mlx_destroy_image(game->ptr, game->img->img);
	mlx_destroy_image(game->ptr, rays->img);
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