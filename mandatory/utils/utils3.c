/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 04:39:58 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 21:28:42 by alaassir         ###   ########.fr       */
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
