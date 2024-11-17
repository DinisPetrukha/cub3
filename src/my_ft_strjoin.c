/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ft_srtlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:24:02 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/11/17 13:34:59 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	my_ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*my_ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*ptr;

	len = my_ft_strlen((char *)s1) + my_ft_strlen((char *)s2);
	i = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s1 && *s1)
		ptr[i++] = *s1++;
	while (s2 && *s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}