/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:55:52 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/12 21:39:24 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;

	i = 0;
	c = (unsigned char)c;
	while (s[i])
		i++;
	p = (char *)s;
	while (i >= 0)
	{
		if (p[i] == c)
			return (&p[i]);
		i--;
	}
	return (0);
}
/*
int	main()
{
	char	*p;
	char	s[7] = "12\0 345";

	p = ft_strrchr(s, 0); 
	printf("%s\n", s);
	p[0] = '8';
	printf("%s\n", p);
	printf("%p\n", ft_strrchr(s, 0));
	printf("%p\n", strrchr(s, 0));
	return (0);
}*/
