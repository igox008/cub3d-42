/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 08:20:06 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 19:58:22 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_line(char **map, int y, t_game *game)
{
	int	x;

	x = -1;
	if (!y || !map[y + 1])
		return (true);
	while (map[y][++x])
	{
		if ((map[y][x] != '1' && map[y][x] != ' ')
			&& (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
			|| map[y][x + 1] == ' ' || map[y][x - 1] == ' '))
			return (false);
		if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '0')
			game->p_view = map[y][x];
	}
	return (true);
}

bool	check_textures(t_game *game)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png(game->ea);
	if (!tmp)
		return (false);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(game->so);
	if (!tmp)
		return (false);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(game->we);
	if (!tmp)
		return (false);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(game->no);
	if (!tmp)
		return (false);
	mlx_delete_texture(tmp);
	return (true);
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
