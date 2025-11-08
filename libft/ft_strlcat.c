/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:31:53 by bnanque           #+#    #+#             */
/*   Updated: 2025/07/31 12:50:08 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	while (dst[i] && i < dstsize)
	i++;
	dst_len = i;
	src_len = 0;
	j = 0;
	while (src[src_len])
		src_len++;
	if (dst_len >= dstsize)
	{
		return (src_len + dstsize);
	}
	while (src[j] && j < dstsize - dst_len - 1)
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	return (dst_len + src_len);
}
