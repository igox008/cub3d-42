/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:13 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/14 00:32:58 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include <time.h>

void    innit_data(t_game *game)
{
    (1) && (game->map = 0, game->ea = NULL, game->no = NULL, game->so = NULL, game->we = NULL);
    (game->floor.b = -1, game->floor.b = -1, game->floor.r = -1);
    (game->ceiling.b = -1, game->ceiling.b = -1, game->ceiling.r = -1);
    game->floor.set = false;
    game->ceiling.set = false;
    game->max_len = -1;
    game->p_cnt = 0;
    game->rotation_speed = 2 * M_PI / 180;
    game->angle_view = get_view(game->p_view);
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
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!game->mlx)
		return (false);
	set_w_h(game);
	game->fp = mlx_load_png("textures/player pov.png");
	if (!game->fp)
		return (false);
	game->rays = g_malloc(sizeof(t_img), MALLOC);
	if (!game->rays)
		return (false);
	game->rays->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->rays->img)
		return (false);
	game->plyr_img = mlx_texture_to_image(game->mlx, game->fp);
	if (!game->plyr_img)
		return (false);
	return (true);
}

void	clear_img(mlx_image_t *img)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(img, x, y, get_rgba(255, 255, 255, 255));
	}
}

void driver(t_game *game)
{
	mlx_key_data_t tmp;
	listen_hook(tmp, game);
	render_game(game);
	// render_map(game, game->rays);
	cast_all_rays(game, game->data);
	// put_player(game, game->rays);
	mlx_image_to_window(game->mlx, game->img->img, 0, 0);
	mlx_image_to_window(game->mlx, game->rays->img, 0, 0);
	mlx_image_to_window(game->mlx, game->plyr_img, (WIDTH / 2) - (500 / 2), HEIGHT - 408);
	// clear_img(game->rays);
	// mlx_destroy_image(game->ptr, game->img->img);
	// mlx_destroy_image(game->ptr, rays->img);
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
	// mlx_key_hook(game.mlx, listen_hook, &game);
	mlx_close_hook(game.mlx, red_x, &game);
	game.data = g_malloc(sizeof(__globl_), MALLOC);
	if (!game.data)
		return (1);
	mlx_loop_hook(game.mlx, driver, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (g_malloc(0, FREE), 0);
}