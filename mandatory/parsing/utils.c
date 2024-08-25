/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:43:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/24 19:34:38 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_p_pos(t_corr *p, char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != '1'
				&& map[y][x] != ' '
				&& map[y][x] != 'D'
				&& map[y][x] != '0')
			{
				p->y = y * TILE_SIZE;
				p->x = x * TILE_SIZE;
				p->y += TILE_SIZE / 2;
				p->x += TILE_SIZE / 2;
				return ;
			}
		}
	}
}

void	set_w_h(t_game *game)
{
	game->w = game->max_len;
	set_p_pos(&game->p_pos, game->map);
}

bool	last_first(char *s)
{
	int	i;

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
	if (*s == '\0')
		return (false);
	else if (*s != '1')
		return (false);
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' && i >= 0)
		i--;
	if (s[i] != '1')
		return (false);
	return (true);
}
