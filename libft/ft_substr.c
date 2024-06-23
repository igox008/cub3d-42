/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:17:53 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/23 06:06:36 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (!len || s_len <= start)
		return (ft_strdup("", MALLOC));
	if (start + len <= s_len)
		sub = (char *)g_malloc(len + 1, MALLOC);
	else
		sub = (char *)g_malloc(s_len - start + 1, MALLOC);
	if (sub == NULL)
		return (NULL);
	while (start + i < s_len && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
