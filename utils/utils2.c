/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:08:56 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/17 00:12:34 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clear_img(mlx_image_t *img)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(img, x, y, get_rgba(255, 255, 255, 0));
	}
}

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
	game->full_map = false;
	game->v.mode = MLX_MOUSE_NORMAL;
}

bool	mlx_engine(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	set_w_h(game);
	(game->mlx) && (game->fp = mlx_load_png("textures/player pov.png"));
	if (!game->mlx || !innit_txtrs(game) || !game->fp)
		return (false);
	game->mini_map = g_malloc(sizeof(t_img), MALLOC);
	game->img = g_malloc(sizeof(t_img), MALLOC);
	game->ray = g_malloc(sizeof(__rays_), MALLOC);
	if (!game->mini_map || !game->img || !game->ray)
		return (false);
	game->img->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->mini_map->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->mini_map->img || !game->img->img)
		return (false);
	game->plyr_img = mlx_texture_to_image(game->mlx, game->fp);
	if (!game->plyr_img)
		return (false);
	mlx_image_to_window(game->mlx, game->img->img, 0, 0);
	mlx_image_to_window(game->mlx, game->plyr_img, (WIDTH / 2) - (500 / 2), HEIGHT - 408);
	mlx_image_to_window(game->mlx, game->mini_map->img, 0, 0);
	return (true);
}
