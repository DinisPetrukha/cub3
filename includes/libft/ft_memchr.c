/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:46:51 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/12 20:43:44 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	c = (unsigned char)c;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	char	str[] = {0, 1, 2, 3, 4, 5};
	int	i;
	i = 0;
	while (i < 6)
	{
		printf("%p %d\n", &str[i], i);
		i++;
	}
	printf("%p\n", (char *)ft_memchr(str, 2 + 256, 3));
	printf("%p\n", (char *)memchr(str, 2 + 256, 3));	
	return (0);
}*/
