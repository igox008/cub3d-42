/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:43:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/09 01:49:38 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_p_pos(t_corr *p, char **map)
{
	p->y = -1;
	while (map[++p->y])
	{
		p->x = -1;
		while (map[p->y][++p->x])
		{
			if (map[p->y][p->x] != '1'
				&& map[p->y][p->x] != ' '
				&& map[p->y][p->x] != '0')
			{
				p->y *= TILE_SIZE;
				p->x *= TILE_SIZE;
				(1) && (p->y += 32, p->x += 32);
				return ;
			}
		}
	}
}

void	set_w_h(t_game *game)
{
	game->h = 0;
	game->w = 0;
	while (game->map[game->h][game->w])
		game->w++;
	while (game->map[game->h])
		game->h++;
	set_p_pos(&game->p_pos, game->map);
}