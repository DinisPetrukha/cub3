/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:50:59 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/12 21:10:16 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n > i)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	int	i = 4;
	char	str1[] = "ABcDEF";
	char	str2[] = "ABCDEF121";
	char	str3[] = {0, 0, 127, 0};
	char	str4[] = {0, 0, 42, 0};

	printf("%d\n", ft_memcmp(str3, str4, i));
	printf("%d\n", memcmp(str1, str2, i));
	return (0);
}*/
