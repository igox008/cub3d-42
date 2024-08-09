/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 08:20:06 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/09 03:52:20 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	last_first(char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != '1' && s[i] != ' ')
			return (false);
	}
	return (true);
}

bool	mdl_line(char *s)
{
	int	i;

	while (s && *s && *s == ' ')
		s++;
	i = ft_strlen(s) - 1;
	if (*s != '1')
		return (false);
	while (s[i] == ' ' && i >= 0)
		i--;
	if (s[i] != '1')
		return (false);
	return (true);
}

void	get_old_map(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = ft_strlen(map[y]) - 1;
		while (x > 0 && map[y][x] == ' ' && map[y][x - 1] == ' ')
			x--;
		map[y][x] = '\0';
	}
}

bool	final_check(char **map, t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if ((map[y][x] != '1' && map[y][x] != ' ') && (map[y - 1][x] == ' '
				|| map[y + 1][x] == ' ' || map[y][x + 1] == ' '
				|| map[y][x - 1] == ' '))
				return (false);
			if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '0')
				game->p_view = map[y][x];
		}
	}
	// get_old_map(map); // need to discuss
	return (true);
}
