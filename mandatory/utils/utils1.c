/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:01:05 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 19:58:10 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	return (true);
}
