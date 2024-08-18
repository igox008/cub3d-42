/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:01:05 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 20:48:26 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	put_player(t_game *game, t_img *img)
{
	int	x;
	int	y;
	int	x_i;
	int	y_i;
	int	tmp_x;

	(void)game;
	(1) && (y = 320 / 2, x = 320 / 2);
	(1) && (tmp_x = x - 7, y_i = y - 7, x += 7, y += 7);
	(y_i < 0) && (y += y_i * -1, y_i = 0);
	(tmp_x < 0) && (x += tmp_x * -1, tmp_x = 0);
	while (y_i <= y && y_i < 320)
	{
		x_i = tmp_x;
		while (x_i <= x && x_i < 320)
		{
			mlx_put_pixel(img->img, x_i, y_i, get_rgba(0, 255, 0, 255));
			x_i++;
		}
		y_i++;
	}
	return (1);
}

int	put_player_full_map(t_game *game, t_img *img, double_t ratio)
{
	t_var	v;

	v.y = (int)game->p_pos.y - 30;
	v.y_i = (int)game->p_pos.y + 30;
	v.x_i = (int)game->p_pos.x + 30;
	while (v.y <= v.y_i)
	{
		v.x = (int)game->p_pos.x - 30;
		while (v.x <= v.x_i)
		{
			mlx_put_pixel(img->img, v.x * ratio, \
			v.y * ratio, get_rgba(0, 255, 0, 200));
			v.x++;
		}
		v.y++;
	}
	return (1);
}

uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

unsigned int	*get_pxls(char *path, t_img *txtr, t_game *g)
{
	unsigned int	*pxls;
	t_var			v;
	mlx_image_t		*img;

	txtr->txtr = mlx_load_png(path);
	(txtr->txtr) && (img = mlx_texture_to_image(g->mlx, txtr->txtr));
	if (!txtr->txtr || !img || !mlx_resize_image(img, TILE_SIZE, TILE_SIZE))
		return (NULL);
	pxls = g_malloc((TILE_SIZE * TILE_SIZE) * sizeof(uint32_t), MALLOC);
	if (!pxls)
		return (NULL);
	(1) && (v.x = 0, v.y = 0);
	while (v.y < TILE_SIZE * TILE_SIZE * 4)
	{
		pxls[v.x++] = (uint32_t)get_rgba(img->pixels[v.y], \
		img->pixels[v.y + 1], img->pixels[v.y + 2], img->pixels[v.y + 3]);
		v.y += 4;
	}
	mlx_delete_texture(txtr->txtr);
	return (txtr->img = img, pxls);
}

bool	innit_txtrs(t_game *game)
{
	game->i_so.pxls = get_pxls(game->so, &game->i_so, game);
	if (!game->i_so.pxls)
		return (false);
	game->i_no.pxls = get_pxls(game->no, &game->i_no, game);
	if (!game->i_no.pxls)
		return (false);
	game->i_we.pxls = get_pxls(game->we, &game->i_we, game);
	if (!game->i_we.pxls)
		return (false);
	game->i_ea.pxls = get_pxls(game->ea, &game->i_ea, game);
	if (!game->i_ea.pxls)
		return (false);
	game->door.pxls = get_pxls(DR, &game->door, game);
	if (!game->door.pxls)
		return (false);
	return (true);
}
