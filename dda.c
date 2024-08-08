/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:19:50 by amel-has          #+#    #+#             */
/*   Updated: 2024/08/08 14:20:51 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	_daa_line(int X0, int Y0, int X1, int Y1,t_game *game) 
{
	int	color = 0x00ff00;
	int	dx = X1 - X0; 
	int	dy = Y1 - Y0; 

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
	float Xinc = dx / (float)steps; 
	float Yinc = dy / (float)steps; 

	float X = X0; 
	float Y = Y0; 
	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(game->img,X,Y, color);
		X += Xinc;
		Y += Yinc;
	}
}
