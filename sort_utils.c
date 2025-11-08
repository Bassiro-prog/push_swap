/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:46:19 by bnanque           #+#    #+#             */
/*   Updated: 2025/09/29 22:10:09 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_node **a, t_node **b)
{
	int	size;
	int	min_pos;
	int	steps;

	min_pos = find_min(*a);
	size = ft_lstsize(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, 1);
	}
	else
	{
		steps = size - min_pos;
		while (steps-- > 0)
			rra(a, 1);
	}
	pb(a, b, 1);
}

int	find_min(t_node *a)
{
	t_node	*current;
	int		min;
	int		min_pos;
	int		i;

	if (!a)
		return (0);
	min_pos = 0;
	current = a;
	min = a->value;
	i = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = i;
		}
		i++;
		current = current->next;
	}
	return (min_pos);
}

void	free_list(t_node **head)
{
	t_node	*tmp;
	t_node	*next;

	tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*head = NULL;
}

int	max_pos_direction(t_node **b, int max_index, int size)
{
	t_node	*pos;
	int		index;
	int		found;

	index = 0;
	found = 0;
	pos = *b;
	while (pos && !found)
	{
		if (pos->index == max_index)
			found = 1;
		else
		{
			index++;
			pos = pos->next;
		}
	}
	if (index < size / 2 + size % 2)
		return (0);
	else
		return (1);
}

int	find_max_value(t_node **a)
{
	int		max_index;
	t_node	*p;

	p = *a;
	max_index = p->index;
	p = p->next;
	while (p != NULL)
	{
		if (max_index < p->index)
			max_index = p->index;
		p = p->next;
	}
	return (max_index);
}
