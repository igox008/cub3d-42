/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:13 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/23 09:19:46 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	innit_data(t_game	*game)
{
	game->map = NULL;
	game->ea = NULL;
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	(game->floor.b = -1, game->floor.b = -1, game->floor.r = -1);
	(game->ceiling.b = -1, game->ceiling.b = -1, game->ceiling.r = -1);
	game->floor.set = false;
	game->ceiling.set = false;
	game->max_len = -1;
	game->p_cnt = 0;
}

int	main(int ac, char **av)
{
	t_game	game;

	innit_data(&game);
	if (ac != 2)
		return (ft_putendl_fd("ERROR", 2), 1);
	if (!parcing(av[1], &game))
		return (g_malloc(0, FREE), 1);
	g_malloc(0, FREE);
	return (0);
}