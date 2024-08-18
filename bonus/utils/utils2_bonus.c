/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:08:56 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 23:36:40 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	clear_img(mlx_image_t *img)
{
	int	y;
	int	x;

	y = -1;
	while (++y < (int)img->height)
	{
		x = -1;
		while (++x < (int)img->width)
			mlx_put_pixel(img, x, y, get_rgba(255, 255, 255, 0));
	}
}

void	innit_data(t_game *game)
{
	(1) && (game->map = 0, game->ea = NULL, \
	game->no = NULL, game->so = NULL, game->we = NULL);
	(1) && (game->floor.b = -1, game->floor.b = -1, \
	game->floor.r = -1);
	(1) && (game->ceiling.b = -1, game->ceiling.b = -1, \
	game->ceiling.r = -1);
	game->floor.set = false;
	game->ceiling.set = false;
	game->max_len = -1;
	game->p_cnt = 0;
	game->rotation_speed = 2 * M_PI / 180;
	game->full_map = false;
	game->v.mode = MLX_MOUSE_NORMAL;
	game->manjal = g_malloc(sizeof(mlx_texture_t *) * 15, MALLOC);
	if (!game->manjal)
		return (ft_putendl_fd("MALLOC ERROR", 2), exit(1));
	(1) && (game->allo = false, game->hayad = false);
	game->stop = false;
}

bool	mlx_engine(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D_bonus", false);
	set_w_h(game);
	(game->mlx) && (game->fp = mlx_load_png(MN));
	if (!game->mlx || !innit_txtrs(game) || !game->fp)
		return (false);
	game->mini_map = g_malloc(sizeof(t_img), MALLOC);
	game->img = g_malloc(sizeof(t_img), MALLOC);
	game->ray = g_malloc(sizeof(t_rays_), MALLOC);
	if (!game->mini_map || !game->img || !game->ray)
		return (false);
	game->img->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->mini_map->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->mini_map->img || !game->img->img)
		return (false);
	game->plyr_img = mlx_new_image(game->mlx, 700, 700);
	if (!game->plyr_img || !game->plyr_img)
		return (false);
	mlx_image_to_window(game->mlx, game->img->img, 0, 0);
	mlx_image_to_window(game->mlx, game->plyr_img, (WIDTH / 2) - \
	(game->plyr_img->width / 2), HEIGHT - game->plyr_img->height);
	draw_txttr(game->plyr_img, game->fp, game);
	print_pos(game);
	mlx_image_to_window(game->mlx, game->mini_map->img, 0, 0);
	return (true);
}

void	draw_txttr(mlx_image_t *img, mlx_texture_t *m, t_game *g)
{
	int			x;
	int			y;
	int			i;
	uint32_t	color;
	mlx_image_t	*t;

	y = 0;
	i = 0;
	t = mlx_texture_to_image(g->mlx, m);
	if (!t || !mlx_resize_image(t, 700, 700))
		return (g_malloc(0, FREE), ft_putendl_fd("ERROR", 2), exit(1));
	while (y < 700)
	{
		x = 0;
		while (x < 700)
		{
			color = get_rgba(t->pixels[i], t->pixels[i + 1], \
			t->pixels[i + 2], t->pixels[i + 3]);
			mlx_put_pixel(img, x, y, color);
			x++;
			i += 4;
		}
		y++;
	}
	mlx_delete_image(g->mlx, t);
}

void	animate_manjal(t_game *game)
{
	static int	it;

	if (!game->manjal[it])
		(1) && (game->hayad = false, it = 0);
	else
	{
		clear_img(game->plyr_img);
		draw_txttr(game->plyr_img, game->manjal[it], game);
	}
	if (game->hayad)
		it++;
}
