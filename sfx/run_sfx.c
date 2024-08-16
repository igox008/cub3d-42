/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sfx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:05:47 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/16 23:06:18 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int play_sound(void)
{
    system("/Users/alaassir/.brew/bin/mpg123 sfx/7ayd_3liya.mp3 > /dev/null 2>&1");
    return (1);
}