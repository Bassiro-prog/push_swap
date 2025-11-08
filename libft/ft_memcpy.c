/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:45:29 by bnanque           #+#    #+#             */
/*   Updated: 2025/07/28 18:47:13 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_cast;
	const unsigned char	*src_cast;

	if (!dst && !src)
		return (NULL);
	dst_cast = (unsigned char *)dst;
	src_cast = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
	dst_cast[i] = src_cast[i];
	i++;
	}
	return (dst);
}
