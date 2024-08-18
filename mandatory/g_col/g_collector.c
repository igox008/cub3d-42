/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:56:47 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/18 14:52:14 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_collector.h"

static t_col	*new_node(void	*ptr)
{
	t_col	*new;

	new = malloc(sizeof(t_col));
	if (!new)
		return (NULL);
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}

static t_col	*last_node(t_col **head)
{
	t_col	*tmp;

	if (!head || !*head)
		return (NULL);
	tmp = *head;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

static t_col	*add_back(t_col	**head, t_col *new)
{
	if (!head || !new)
		return (NULL);
	if (!*head)
		*head = new;
	else
		last_node(head)->next = new;
	return (new);
}

static void	clear_all(t_col **head)
{
	t_col	*cur;
	t_col	*tmp;

	if (!head || !*head)
		return ;
	cur = *head;
	while (cur)
	{
		tmp = cur->next;
		free(cur->ptr);
		cur->ptr = NULL;
		free(cur);
		cur = tmp;
	}
	*head = NULL;
}

void	*g_malloc(size_t size, t_call call)
{
	static t_col	*long_term;
	static t_col	*short_term;
	void			*ptr;

	if (call == MALLOC || call == MALLOC_S)
	{
		ptr = malloc(size);
		if (!ptr && call == MALLOC)
			return (clear_all(&long_term), NULL);
		else if (!ptr && call == MALLOC_S)
			return (clear_all(&short_term), NULL);
		if (call == MALLOC && !add_back(&long_term, new_node(ptr)))
			return (clear_all(&long_term), free(ptr), NULL);
		else if (call == MALLOC_S && !add_back(&short_term, new_node(ptr)))
			return (clear_all(&short_term), free(ptr), NULL);
		return (ptr);
	}
	else if (call == FREE)
		clear_all(&long_term);
	else if (call == FREE_S)
		clear_all(&short_term);
	return (NULL);
}
