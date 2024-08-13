/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:13 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/13 03:39:01 by alaassir         ###   ########.fr       */
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
	mlx_set_setting(MLX_MAXIMIZED, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!game->mlx)
		return (false);
	set_w_h(game);
	game->fp = mlx_load_png("textures/player pov.png");
	if (!game->fp)
		return (false);
	return (true);
}

void driver(t_game *game)
{
	t_img	*rays;
	mlx_image_t	*tmp;

	rays = malloc(sizeof(t_img));
	if (!rays)
		return (g_malloc(0, FREE), exit(1));
	rays->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!rays->img)
		return (g_malloc(0, FREE), free(rays), exit(1));
	game->rays = rays;
	render_game(game);
	render_map(game, rays);
	cast_all_rays(game, game->data);
	put_player(game, rays);
	tmp = mlx_texture_to_image(game->mlx, game->fp);
	mlx_image_to_window(game->mlx, game->img->img, 0, 0);
	mlx_image_to_window(game->mlx, rays->img, 0, 0);
	mlx_image_to_window(game->mlx, tmp, (WIDTH / 2) - (500 / 2), HEIGHT - 408);
	// mlx_destroy_image(game->ptr, game->img->img);
	// mlx_destroy_image(game->ptr, rays->img);
	return (free(rays));
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
	mlx_key_hook(game.mlx, listen_hook, &game);
	mlx_close_hook(game.mlx, red_x, &game);
	game.data = g_malloc(sizeof(__globl_), MALLOC);
	if (!game.data)
		return (1);
	mlx_loop_hook(game.mlx, driver, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	g_malloc(0, FREE);
	return (0);
}