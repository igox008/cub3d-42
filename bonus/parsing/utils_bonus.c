/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:43:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/24 20:05:37 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	set_p_pos(t_corr *p, char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != '1'
				&& map[y][x] != ' '
				&& map[y][x] != 'D'
				&& map[y][x] != '0')
			{
				p->y = y * TILE_SIZE;
				p->x = x * TILE_SIZE;
				p->y += TILE_SIZE / 2;
				p->x += TILE_SIZE / 2;
				return ;
			}
		}
	}
}

void	set_w_h(t_game *game)
{
	game->w = game->max_len;
	set_p_pos(&game->p_pos, game->map);
}

bool	last_first(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != '1' && s[i] != ' ')
			return (false);
	}
	return (true);
}

bool	mdl_line(char *s)
{
	int	i;

	while (s && *s && *s == ' ')
		s++;
	if (*s == '\0')
		return (false);
	else if (*s != '1')
		return (false);
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' && i >= 0)
		i--;
	if (s[i] != '1')
		return (false);
	return (true);
}

char	*get_path(char *line)
{
	int		i;
	char	*tmp;

	line = till_char(line + 2);
	if (!line || count_w(line, " ") != 1)
	{
		(1) && (g_malloc(0, FREE), g_malloc(0, FREE_S));
		ft_putendl_fd("ERROR", 2);
		return (exit(1), NULL);
	}
	i = ft_strlen(line) - 1;
	while (line[i] == ' ' && i >= 0)
		i--;
	if (line[i] != ' ')
		i++;
	line[i] = '\0';
	tmp = ft_strdup(line, MALLOC);
	if (!tmp)
		return (NULL);
	return (tmp);
}
