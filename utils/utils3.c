/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 04:39:58 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/17 05:37:29 by alaassir         ###   ########.fr       */
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
