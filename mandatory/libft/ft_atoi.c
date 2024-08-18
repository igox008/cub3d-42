/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:42:06 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 20:52:17 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				s;
	unsigned long	rsl;

	(1) && (i = 0, s = 1, rsl = 0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rsl = (rsl * 10) + (str[i] - 48);
		if (rsl > LONG_MAX && s == 1)
			return (-1);
		else if (rsl > LONG_MAX && s == -1)
			return (0);
		i++;
	}
	return (rsl * s);
}
