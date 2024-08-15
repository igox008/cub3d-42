/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 05:53:49 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/15 02:25:04 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_valid_rgb(int rgb, char *s)
{
	if (rgb > 255 || rgb < 0)
		return (false);
	else if (ft_intlen(s) > 3)
		return (false);
	return (true);
}

bool	check_assets(t_game *game)
{
	if (!game->ea || !game->no || !game->so || !game->we)
		return (false);
	else if (!game->ceiling.set || !game->floor.set)
		return (false);
	return (true);
}



bool	not_valid_char(char *line, t_game *game)
{
	int			i;

	i = -1;
	while (line[++i] && line[i] != '\n')
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			game->p_cnt++;
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
			return (false);
		if (game->p_cnt > 1)
			return (false);
	}
	return (true);
}

char	**get_map(t_game *game, char *last, int fd)
{
	char	*tmp;
	char	*all;

	all = ft_strjoin(last, "\n", MALLOC_S);
	if (!all)
		return (NULL);
	tmp = get_next_line(fd);
	while (tmp)
	{
		all = ft_strjoin(all, tmp, MALLOC_S);
		if (*tmp == '\n' || !all || !not_valid_char(tmp, game))
			return (NULL);
		if (game->max_len < (int)ft_strlen(tmp))
			game->max_len = ft_strlen(tmp);
		tmp = get_next_line(fd);
	}
	if (all && all[ft_strlen(all) - 1] == '\n')
		return (NULL);
	return (ft_split(all, "\n", MALLOC));
}

bool	final_map(t_game *game, char *last, int fd)
{
	int	i;

	i = 0;
	game->map = get_map(game, last, fd);
	if (!game->map || game->p_cnt != 1)
		return (false);
	while (game->map[i])
	{
		if ((i == 0 || !game->map[i + 1]) && !last_first(game->map[i]))
			return (false);
		else if (!mdl_line(game->map[i]))
			return (false);
		while ((int)ft_strlen(game->map[i]) < game->max_len)
		{
			game->map[i] = ft_strjoin(game->map[i], " ", MALLOC);
			if (!game->map[i])
				return (false);
		}
		i++;
	}
	return (true);
}
