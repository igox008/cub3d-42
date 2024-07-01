/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:01:05 by alaassir          #+#    #+#             */
/*   Updated: 2024/07/01 18:53:55 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	put_player(t_game *game, t_img *img)
{
	int	x;
	int	y;

	y = game->p_pos.y + 4;
	while (y < game->p_pos.y + 16)
	{
		x = game->p_pos.x + 4;
		while (x < game->p_pos.x + 16)
		{
			my_mlx_pixel_put(img, x, y, GRAY);
			x++;
		}
		y++;
	}
	return (1);
}
