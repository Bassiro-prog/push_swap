/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:15:39 by bnanque           #+#    #+#             */
/*   Updated: 2025/09/27 16:58:13 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (*lst == NULL)
	{
	*lst = new;
		return ;
	}
	else
	{
	last = ft_lstlast(*lst);
	last->next = new;
	}
}
