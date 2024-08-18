/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse01_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 08:20:06 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 21:11:59 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

bool	check_door(char **map, int x, int y)
{
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1'
		&& map[y][x - 1] != ' ' && map[y][x + 1] != ' ')
		return (true);
	else if (map[y][x - 1] == '1' && map[y][x + 1] == '1'
		&& map[y + 1][x] != ' ' && map[y - 1][x] != ' ')
		return (true);
	return (false);
}

bool	check_line(char **map, int y, t_game *game)
{
	int	x;

	x = -1;
	if (!y || !map[y + 1])
		return (true);
	while (map[y][++x])
	{
		if (map[y][x] == 'D' && !check_door(map, x, y))
			return (false);
		else if ((map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != 'D')
			&& (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
			|| map[y][x + 1] == ' ' || map[y][x - 1] == ' '))
			return (false);
		if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '0')
			game->p_view = map[y][x];
	}
	return (true);
}

bool	check_textures_norm(void)
{
	mlx_texture_t	*tmp;

	tmp = load_txtr(MN6);
	mlx_delete_texture(tmp);
	tmp = load_txtr(MN7);
	mlx_delete_texture(tmp);
	tmp = load_txtr(DR);
	mlx_delete_texture(tmp);
	return (true);
}

bool	check_textures(t_game *game)
{
	mlx_texture_t	*tmp;

	tmp = load_txtr(game->ea);
	mlx_delete_texture(tmp);
	tmp = load_txtr(game->so);
	mlx_delete_texture(tmp);
	tmp = load_txtr(game->we);
	mlx_delete_texture(tmp);
	tmp = load_txtr(game->no);
	mlx_delete_texture(tmp);
	tmp = load_txtr(MN);
	mlx_delete_texture(tmp);
	tmp = load_txtr(MN1);
	mlx_delete_texture(tmp);
	tmp = load_txtr(MN2);
	mlx_delete_texture(tmp);
	tmp = load_txtr(MN3);
	mlx_delete_texture(tmp);
	tmp = load_txtr(MN4);
	mlx_delete_texture(tmp);
	tmp = load_txtr(MN5);
	mlx_delete_texture(tmp);
	return (check_textures_norm());
}

char	*get_n_space(int n)
{
	char	*ret;
	int		i;

	ret = g_malloc(n + 1, MALLOC_S);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < n)
		ret[i] = ' ';
	ret[i] = '\0';
	return (ret);
}
