/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:45:41 by sephilip          #+#    #+#             */
/*   Updated: 2024/09/29 13:18:38 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	j;

	len = 0;
	while (len < size && dst[len])
		len++;
	j = ft_strlen(src);
	if (len == size)
		return (len + j);
	i = 0;
	while (src[i] && (i < size - len - 1))
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = 0;
	return (len + j);
}
/*
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*pt_src;

	pt_src = (char *)src;
	i = 0;
	while (i < size && *dst)
	{
		dst++;
		i++;
	}
	if (i == size)
		return (i + ft_strlen(src));
// i == size of dst
	j = 0;
	while (pt_src[j])
	{
		if (j < size - i - 1)
			*dst++ = pt_src[j];
		j++;
	}
	*dst = 0;
	return (j + i);
}

int	main()
{
	char	d[30]; memset(d, 0, 30);
	char	s[] = "AAAAAAAAA";
	d[0] = 'B';

	//printf"%d\n", ft_strlcat(d, s, 4));
	//printf"%d\n", strlen(s));
	//printf"%d\n", strcmp(d, "B"));
	//printf"%s\n", d);
	//printf"%s\n", s);
	return (0);
}*/
