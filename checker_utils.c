/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:09:28 by bnanque           #+#    #+#             */
/*   Updated: 2025/10/02 12:09:28 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_operation2(char *line, t_node **a, t_node **b)
{
	if (!ft_strcmp(line, "rrr\n"))
	{
		rra(a, 0);
		rrb(b, 0);
		return (0);
	}
	if (!ft_strcmp(line, "pa\n"))
	{
		pa(a, b, 0);
		return (0);
	}
	if (!ft_strcmp(line, "rra\n"))
	{
		rra(a, 0);
		return (0);
	}
	if (!ft_strcmp(line, "rrb\n"))
	{
		rrb(b, 0);
		return (0);
	}
	return (1);
}

int	do_operation1(char *line, t_node **a, t_node **b)
{
	if (!ft_strcmp(line, "sa\n"))
	{
		sa(a, 0);
		return (0);
	}
	if (!ft_strcmp(line, "sb\n"))
	{
		sb(b, 0);
		return (0);
	}
	if (!ft_strcmp(line, "ss\n"))
	{
		sa(a, 0);
		sb(b, 0);
		return (0);
	}
	if (!ft_strcmp(line, "pb\n"))
	{
		pb(a, b, 0);
		return (0);
	}
	return (1);
}

int	do_operation(char *line, t_node **a, t_node **b)
{
	if (!do_operation1(line, a, b))
		return (0);
	if (!do_operation2(line, a, b))
		return (0);
	if (!ft_strcmp(line, "ra\n"))
	{
		ra(a, 0);
		return (0);
	}
	if (!ft_strcmp(line, "rb\n"))
	{
		rb(b, 0);
		return (0);
	}
	if (!ft_strcmp(line, "rr\n"))
	{
		ra(a, 0);
		rb(b, 0);
		return (0);
	}
	return (1);
}

void	init_helper(int argc, char **argv, char ***args, int *i)
{
	if (argc == 2)
	{
		*args = ft_split(argv[1], ' ');
		*i = 0;
	}
	else
	{
		*args = argv;
		*i = 1;
	}
}
