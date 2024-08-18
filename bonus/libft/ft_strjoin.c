/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:09:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/04/06 21:54:53 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, t_call call)
{
	int		i;
	int		t;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("", call);
	t = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)g_malloc(t + 1, call);
	if (new == NULL)
		return (NULL);
	while (j < ft_strlen(s1))
		new[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
