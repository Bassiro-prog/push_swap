/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:21:52 by bnanque           #+#    #+#             */
/*   Updated: 2025/07/31 11:19:43 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
	set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	size_t	len;
	char	*trimmed;

	first = 0;
	if (!s1 && !set)
		return (NULL);
	while (s1[first] && is_in_set(s1[first], set))
		first++;
	last = ft_strlen(s1);
	while (last > first && is_in_set(s1[last - 1], set))
		last--;
	len = last - first;
	trimmed = malloc(len + 1);
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s1 + first, len);
	trimmed[len] = '\0';
	return (trimmed);
}
