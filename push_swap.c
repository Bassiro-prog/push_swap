/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:34:02 by bnanque           #+#    #+#             */
/*   Updated: 2025/09/29 19:36:25 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack(int argc, char **argv, t_node **a)
{
	int		i;
	char	**tokens;

	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
		{
			free_split(tokens);
			print_error_and_exit();
		}
		parsing_tokens(tokens, a);
		free_split(tokens);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	fill_stack(argc, argv, &a);
	check_duplicates(a);
	if (is_sorted(a))
	{
		free_list(&a);
		return (0);
	}
	sort_stack(&a, &b);
	free_list(&a);
	free_list(&b);
	return (0);
}
