/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 04:39:58 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 18:34:19 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

mlx_texture_t	*load_txtr(char *path)
{
	mlx_texture_t	*ret;

	ret = mlx_load_png(path);
	if (!ret)
	{
		ft_putendl_fd("ERROR", 2);
		(1) && (g_malloc(0, FREE), g_malloc(0, FREE_S));
		exit(1);
	}
	return (ret);
}

void	innit_manjal(mlx_texture_t **arr)
{
	arr[0] = load_txtr(MN1);
	arr[1] = load_txtr(MN2);
	arr[2] = load_txtr(MN3);
	arr[3] = load_txtr(MN4);
	arr[4] = load_txtr(MN5);
	arr[5] = load_txtr(MN6);
	arr[6] = load_txtr(MN7);
	arr[7] = arr[5];
	arr[8] = arr[4];
	arr[9] = arr[3];
	arr[10] = arr[2];
	arr[11] = arr[1];
	arr[12] = arr[0];
	arr[13] = load_txtr(MN);
	arr[14] = NULL;
}

bool	norm_rm(t_var v, t_game *g)
{
	if (v.y > 0 && v.x > 0 && v.y < g->h * TILE_SIZE && v.x < g->w * TILE_SIZE)
		return (true);
	return (false);
}

void	_door_(t_game *game, bool open, t_globl_ *data)
{
	int			x;
	int			y;

	(1) && (x = (int)game->p_pos.x / TILE_SIZE, \
	y = (int)game->p_pos.y / TILE_SIZE);
	if (data->facing_down && open && game->map[y + 1][x] == 'D')
		game->map[y + 1][x] = 'O';
	else if (data->facing_up && open && game->map[y - 1][x] == 'D')
		game->map[y - 1][x] = 'O';
	else if (data->facing_left && open && game->map[y][x - 1] == 'D')
		game->map[y][x - 1] = 'O';
	else if (data->facing_right && open && game->map[y][x + 1] == 'D')
		game->map[y][x + 1] = 'O';
	else if (data->facing_down && !open && game->map[y + 1][x] == 'O')
		game->map[y + 1][x] = 'D';
	else if (data->facing_up && !open && game->map[y - 1][x] == 'O')
		game->map[y - 1][x] = 'D';
	else if (data->facing_left && !open && game->map[y][x - 1] == 'O')
		game->map[y][x - 1] = 'D';
	else if (data->facing_right && !open && game->map[y][x + 1] == 'O')
		game->map[y][x + 1] = 'D';
}
