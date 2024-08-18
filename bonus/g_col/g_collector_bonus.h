/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collector_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:53:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 20:31:43 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_COLLECTOR_BONUS_H
# define G_COLLECTOR_BONUS_H

# include <stdlib.h>

typedef struct s_col
{
	void			*ptr;
	struct s_col	*next;
}	t_col;

typedef enum e_call
{
	FREE,
	FREE_S,
	MALLOC,
	MALLOC_S
}	t_call;

void	*g_malloc(size_t size, t_call call);

#endif