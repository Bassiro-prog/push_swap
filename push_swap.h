/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:49:32 by bnanque           #+#    #+#             */
/*   Updated: 2025/10/02 12:19:34 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"

/* ===== Error ===== */
void	print_error_and_exit(void);

/* ===== Stack utils ===== */
t_node	*new_node(int value);
void	add_back(t_node **head, t_node *new);
void	free_list(t_node **head);
int		ft_lstsize(t_node *a);
int		is_sorted(t_node *head);
void	check_duplicates(t_node *head);
void	normalizer(t_node *a);

/* ===== Operations ===== */
void	swap(t_node **head);
void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	ss(t_node **a, t_node **b, int print);
void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **a, t_node **b, int print);
void	rotate(t_node **head);
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	rr(t_node **a, t_node **b, int print);
void	rev_rotate(t_node **head);
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	rrr(t_node **a, t_node **b, int print);

/* ===== Sorting ===== */
void	sort_stack(t_node **a, t_node **b);
void	sort_3(t_node **a);
void	sort_5(t_node **a, t_node **b);
void	sort_big(t_node **a, t_node **b, int chunk_size);
void	push_min_to_b(t_node **a, t_node **b);
void	sort_and_pa(t_node **a, t_node **b);
int		find_min(t_node *a);
int		find_max_value(t_node **a);
int		max_pos_direction(t_node **b, int max_index, int size);

/* ===== Parsing ===== */
int		is_numeric_string(const char *s);
void	free_split(char **arr);
void	parsing_tokens(char **tokens, t_node **a);

/*===== Bonus utils ====*/
void	init_stack(t_node **stack, int argc, char **argv);
void	print_checker_result(t_node *a, t_node *b);
int		do_operation(char *line, t_node **a, t_node **b);
int		do_operation1(char *line, t_node **a, t_node **b);
int		do_operation2(char *line, t_node **a, t_node **b);
void	print_error_and_exit1(t_node **a, t_node **b, char *line);
void	init_helper(int argc, char **argv, char ***args, int *i);
#endif
