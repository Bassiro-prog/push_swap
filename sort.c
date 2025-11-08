/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:06:36 by bnanque           #+#    #+#             */
/*   Updated: 2025/09/29 22:19:09 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **a, t_node **b)
{
	int	size;

	if (!a || !(*a) || is_sorted(*a))
		return ;
	size = ft_lstsize(*a);
	normalizer(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, 1);
	}
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
	{
		push_min_to_b(a, b);
		sort_3(a);
		pa(a, b, 1);
	}
	else if (size == 5)
		sort_5(a, b);
	else if (size <= 100)
		sort_big(a, b, 20);
	else if (size > 100)
		sort_big(a, b, 45);
}

void	sort_3(t_node **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third && first > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

void	sort_5(t_node **a, t_node **b)
{
	if (!a || !(*a) || !(*a)->next)
		return ;
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_3(a);
	if ((*b) && (*b)->next && (*b)->value < (*b)->next->value)
		sb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
}

void	sort_big(t_node **a, t_node **b, int chunk_size)
{
	int	i;

	i = 0;
	while ((*a) != NULL)
	{
		if (i > 0 && (*a)->index < i)
		{
			pb(a, b, 1);
			if ((*a) && (*a)->index >= i + chunk_size)
				rr(a, b, 1);
			else
				rb(b, 1);
			i++;
		}
		else if ((*a)->index < i + chunk_size)
		{
			pb(a, b, 1);
			i++;
		}
		else if ((*a)->index >= i + chunk_size)
			ra(a, 1);
	}
	sort_and_pa(a, b);
}

int	is_sorted(t_node *head)
{
	if (!head)
		return (1);
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
