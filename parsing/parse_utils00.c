/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 02:06:38 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/15 02:11:56 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

char	*till_char(char *line)
{
	while (line && *line)
	{
		if (*line != ' ' && ft_isspace(*line))
			return (NULL);
		else if (*line != ' ')
			return (line);
		line++;
	}
	return (NULL);
}

int	cnt_c(char *s, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == c)
			count++;
	}
	return (count);
}

bool	is_rgb(char *line)
{
	char	*tmp;

	tmp = till_char(line);
	if (!tmp)
		return (false);
	if (!ft_strncmp(tmp, "F ", 2) || !ft_strncmp(tmp, "C ", 2))
		return (true);
	return (false);
}

bool	parse_rgb(char **arr, char *line, t_rgb *rgb)
{
	int	i;

	if (rgb->set)
		return (false);
	if (!arr|| cnt_c(line, ',') != 2)
		return (false);
	i = -1;
	while (arr[++i])
	{
		if (i >= 3 || !ft_all_digit(arr[i]))
			return (false);
	}
	rgb->r = ft_atoi(arr[0]);
	rgb->g = ft_atoi(arr[1]);
	rgb->b = ft_atoi(arr[2]);
	if (!is_valid_rgb(rgb->r, arr[0])
		|| !is_valid_rgb(rgb->g, arr[1])
		|| !is_valid_rgb(rgb->b, arr[2]))
		return (false);
	rgb->set = true;
	return (true);
}
