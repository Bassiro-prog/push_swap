/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:28:34 by bnanque           #+#    #+#             */
/*   Updated: 2025/07/31 11:52:30 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	if (size != 0 && count > (size_t)(-1) / size)
		return (NULL);
	total = (count * size);
	ptr = malloc(total);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
