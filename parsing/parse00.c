/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:44:31 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/10 02:31:44 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_ext(char *file)
{
	char	*tmp;

	tmp = ft_strrchr(file, '.');
	if (!tmp)
		return (false);
	if (!ft_strcmp(tmp, ".cub"))
		return (true);
	return (false);
}

bool	read_map(char *file, t_game *game, int fd)
{
	char	*tmp;
	char	*all;
	int		len;

	all = NULL;
	len = -1;
	tmp = get_next_line(fd);
	while (tmp)
	{
		all = ft_strjoin(all, tmp, MALLOC);
		if (!all)
			return (false);
		if (len < ft_strlen(tmp))
			len = ft_strlen(tmp);
		tmp = get_next_line(fd);
	}
	game->map = ft_split(tmp, "\n");
	if (!game->map)
		return (false);
	return (true);
}

bool	parcing(char *file, t_game *game)
{
	int	fd;

	if (!check_ext(file))
		return (false);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	return (true);
}