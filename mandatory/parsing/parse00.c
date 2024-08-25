/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:44:31 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/25 20:10:48 by alaassir         ###   ########.fr       */
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

char	*skip_empty(int fd)
{
	char	*ret;

	ret = get_next_line(fd);
	while (ret)
	{
		while (ret && *ret == ' ')
			ret++;
		if (ft_strcmp(ret, "\n"))
			break ;
		ret = get_next_line(fd);
	}
	if (ret)
		ret[ft_strlen(ret) - 1] = '\0';
	return (ret);
}

bool	hndl_rgb(t_game *game, char *line)
{
	char	*tmp;
	char	**arr;

	tmp = till_char(line);
	if (*tmp == 'F')
	{
		tmp = till_char(tmp + 1);
		if (!tmp)
			return (false);
		arr = ft_split(tmp, ", ", MALLOC_S);
		if (!parse_rgb(arr, tmp, &game->floor))
			return (false);
	}
	else
	{
		tmp = till_char(tmp + 1);
		if (!tmp)
			return (false);
		arr = ft_split(tmp, ", ", MALLOC_S);
		if (!parse_rgb(arr, tmp, &game->ceiling))
			return (false);
	}
	return (true);
}

char	*get_assets(int fd, t_game *game)
{
	char	*tmp;

	tmp = skip_empty(fd);
	while (tmp)
	{
		(1) && (game->last = ft_strdup(tmp, \
		MALLOC_S), tmp = till_char(tmp));
		if (!tmp)
			return (NULL);
		if (!game->ea && !ft_strncmp(tmp, "EA ", 3))
			game->ea = ft_strdup(till_char(tmp + 2), MALLOC);
		else if (!game->no && !ft_strncmp(tmp, "NO ", 3))
			game->no = ft_strdup(till_char(tmp + 2), MALLOC);
		else if (!game->so && !ft_strncmp(tmp, "SO ", 3))
			game->so = ft_strdup(till_char(tmp + 2), MALLOC);
		else if (!game->we && !ft_strncmp(tmp, "WE ", 3))
			game->we = ft_strdup(till_char(tmp + 2), MALLOC);
		else if (is_rgb(tmp) && !hndl_rgb(game, tmp))
			return (NULL);
		else if (!is_rgb(tmp))
			break ;
		tmp = skip_empty(fd);
	}
	(!check_assets(game)) && (tmp = NULL);
	return (tmp);
}

bool	parcing(char *file, t_game *game)
{
	int		fd;
	char	*tmp;

	if (!check_ext(file))
		return (ft_putendl_fd("ERROR", 2), false);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("ERROR", 2), false);
	tmp = get_assets(fd, game);
	if (!tmp || !final_map(game, game->last, fd))
		return (close(fd), ft_putendl_fd("ERROR", 2), false);
	game->floor.hex = get_rgba(game->floor.r, \
	game->floor.g, game->floor.b, 255);
	game->ceiling.hex = get_rgba(game->ceiling.r, \
	game->ceiling.g, game->ceiling.b, 255);
	g_malloc(0, FREE_S);
	return (true);
}
