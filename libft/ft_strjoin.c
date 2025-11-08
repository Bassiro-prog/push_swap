/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:47:33 by bnanque           #+#    #+#             */
/*   Updated: 2025/07/31 11:18:45 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
