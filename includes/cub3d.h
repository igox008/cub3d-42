/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:39:07 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/10 02:31:54 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include "../g_col/g_collector.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include <fcntl.h>

typedef struct  s_game
{
    char    **map;
}   t_game;

bool	parcing(char *file, t_game *game);

#endif
