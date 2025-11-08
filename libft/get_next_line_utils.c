/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:34:40 by bnanque           #+#    #+#             */
/*   Updated: 2025/08/11 17:16:35 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
	dest[i] = '\0';
		i++;
	}
}

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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resul;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	resul = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!resul)
		return (NULL);
	while (s1[i])
	{
	resul[i] = s1[i];
	i++;
	}
	while (s2[j])
	{
	resul[i + j] = s2[j];
	j++;
	}
	resul[i + j] = '\0';
	return (resul);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
	s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
