/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:13 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/16 06:14:08 by alaassir         ###   ########.fr       */
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
	// game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!game->mlx)
		return (false);
	set_w_h(game);
	game->fp = mlx_load_png("textures/player pov.png");
	game->wall.txtr = mlx_load_png("textures/wall.png");
	game->wall.img = mlx_texture_to_image(game->mlx, game->wall.txtr);
	mlx_resize_image(game->wall.img, TILE_SIZE, TILE_SIZE);
	game->wall.pxls = get_pxls(game->wall.img);
	if (!game->fp || !game->wall.txtr)
		return (false);
	game->mini_map = g_malloc(sizeof(t_img), MALLOC);
	if (!game->mini_map)
		return (false);
	game->img = g_malloc(sizeof(t_img), MALLOC);
	if (!game->img)
		return (false);
	game->ray = g_malloc(sizeof(__rays_), MALLOC);
	if (!game->ray)
		return (false);
	game->img->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->mini_map->img = mlx_new_image(game->mlx, 320, 320);
	if (!game->mini_map->img || !game->img->img)
		return (false);
	game->plyr_img = mlx_texture_to_image(game->mlx, game->fp);
	if (!game->plyr_img)
		return (false);
	mlx_image_to_window(game->mlx, game->img->img, 0, 0);
	mlx_image_to_window(game->mlx, game->mini_map->img, 0, 0);
	mlx_image_to_window(game->mlx, game->plyr_img, (WIDTH / 2) - (500 / 2), HEIGHT - 408);
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

void driver(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	listen_hook(ptr);
	render_map(game, game->mini_map, game->v);
	cast_all_rays(game, game->data);
	// put_player(game, game->mini_map);
	// mlx_image_to_window(game->mlx, game->mini_map->img, 0, 0);
	
	// mlx_destroy_image(game->ptr, game->img->img);
	// mlx_destroy_image(game->ptr, rays->img);
	// g_malloc(0, GET_SIZE);
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
	game.data = g_malloc(sizeof(__globl_), MALLOC);
	if (!game.data)
		return (1);
	game.ratio = 0.5;
	mlx_close_hook(game.mlx, red_x, (void *)&game);
	mlx_loop_hook(game.mlx, driver, (void *)&game);
	// mlx_key_hook(game.mlx, listen_hook, (void *)&game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (g_malloc(0, FREE), 0);
}