/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:40:06 by bnanque           #+#    #+#             */
/*   Updated: 2025/09/29 22:07:15 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalizer(t_node *a)
{
	t_node	*i;
	t_node	*j;
	int		index;

	i = a;
	while (i)
	{
		index = 0;
		j = a;
		while (j)
		{
			if (j->value < i->value)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}

t_node	*new_node(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->index = 0;
	n->next = NULL;
	return (n);
}

void	add_back(t_node **head, t_node *new)
{
	t_node	*temp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	ft_lstsize(t_node *a)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = a;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	sort_and_pa(t_node **a, t_node **b)
{
	int	max;
	int	size_b;

	while (*b != NULL)
	{
		max = find_max_value(b);
		size_b = ft_lstsize(*b);
		if ((*b)->index != max)
		{
			if (!max_pos_direction(b, max, size_b))
				rb(b, 1);
			else
				rrb(b, 1);
		}
		else
			pa(a, b, 1);
	}
}
