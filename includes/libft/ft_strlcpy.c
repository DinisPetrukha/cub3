/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:57:58 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/19 20:25:38 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// restrict forbidden

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (!size)
		return (len);
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len);
}

// BYTE FOR THE NULL INCLUDED IN SIZE
/*
int	main()
{
	char	d[10]; memset(d, 'A', 10);
	char	s[] = "coucou";

	printf("%d\n", ft_strlcpy(d, s, 0));
	printf("%d\n", strlen(s));
	printf("%d\n", d[0] == 'A');
	printf("%s\n", d);
	printf("%s\n", s);
	return (0);
}*/
