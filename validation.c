/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:20:39 by bnanque           #+#    #+#             */
/*   Updated: 2025/09/30 13:42:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric_string(const char *s)
{
	int	i;

	if (!s || *s == '\0')
		return (0);
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '\0')
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
	i++;
	}
	return (1);
}

void	free_split(char **arr)
{
	int		i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
	i++;
	}
	free(arr);
}

void	print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	parsing_tokens(char **tokens, t_node **a)
{
	int		i;
	long	num;

	i = 0;
	while (tokens[i])
	{
		if (!is_numeric_string(tokens[i]))
		{
			free_split(tokens);
			print_error_and_exit();
		}
		num = ft_atol(tokens[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			free_split(tokens);
			print_error_and_exit();
		}
		add_back(a, new_node((int)num));
		i++;
	}
}

void	check_duplicates(t_node *head)
{
	t_node	*i;
	t_node	*j;

	if (!head)
		return ;
	i = head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (j->value == i->value)
				print_error_and_exit();
			j = j->next;
		}
		i = i->next;
	}
}
