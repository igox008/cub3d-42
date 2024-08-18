/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sfx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:05:47 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 19:10:05 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	make_sound_thread(t_game *game)
{
	if (pthread_mutex_init(&game->mtx, NULL) == -1)
	{
		(1) && (g_malloc(0, FREE), g_malloc(0, FREE_S));
		ft_putendl_fd("ERROR : mutex", 2);
		exit(1);
	}
	if (pthread_create(&game->thrd, NULL, play_sound, (void *)game) == -1)
	{
		(1) && (g_malloc(0, FREE), g_malloc(0, FREE_S));
		ft_putendl_fd("ERROR : Thread", 2);
		pthread_mutex_destroy(&game->mtx);
		exit(1);
	}
	pthread_detach(game->thrd);
}

int	set_bool(t_game *game, bool set, bool *org)
{
	pthread_mutex_lock(&game->mtx);
	*org = set;
	pthread_mutex_unlock(&game->mtx);
	return (1);
}

bool	get_bool(t_game *game, bool *get)
{
	bool	ret;

	pthread_mutex_lock(&game->mtx);
	ret = *get;
	pthread_mutex_unlock(&game->mtx);
	return (ret);
}

void	*play_sound(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	while (!get_bool(game, &game->stop))
	{
		if (get_bool(game, &game->allo))
			(1) && (system("/Users/alaassir/.brew/bin/mpg123 sfx/7ayd_3liya.mp3 \
			> /dev/null 2>&1"), set_bool(game, false, &game->allo));
	}
	return (NULL);
}
