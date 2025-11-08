/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:37:58 by bnanque           #+#    #+#             */
/*   Updated: 2025/07/31 11:18:04 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	dst = (char *)dest;
	s = (const char *)src;
	if (dst < s)
		ft_memcpy(dst, s, n);
	else
	{
		while (n--)
			dst[n] = s[n];
	}
	return (dest);
}
