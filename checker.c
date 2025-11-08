/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:32:33 by bnanque           #+#    #+#             */
/*   Updated: 2025/10/02 11:59:14 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_checker_result(t_node *a, t_node *b)
{
	if (is_sorted(a) && b == NULL)
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	free_list(&a);
	free_list(&b);
}

void	init_stack(t_node **stack, int argc, char **argv)
{
	int		i;
	char	**args;
	t_node	*new;

	init_helper(argc, argv, &args, &i);
	while (args[i])
	{
		if (!is_numeric_string(args[i]))
		{
			if (argc == 2)
				free_split(args);
			print_error_and_exit();
		}
		new = new_node(ft_atol(args[i]));
		add_back(stack, new);
		i++;
	}
	normalizer(*stack);
	if (argc == 2)
		free_split(args);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	init_stack(&a, argc, argv);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (do_operation(line, &a, &b))
		{
			free(line);
			print_error_and_exit();
			return (-1);
		}
		free(line);
		line = get_next_line(0);
	}
	print_checker_result(a, b);
	return (0);
}
