/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:38:38 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/12 21:36:40 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	c = (unsigned char)c;
	p = (char *)s;
	i = 0;
	while (p[i])
	{
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	if (c == 0)
		return (&p[i]);
	return (0);
}
/*
int	main()
{
	char	s[] =  "BROVSKI123";

	printf("%s\n", ft_strchr(s, 'B' + 256));
	printf("%s\n", strchr(s, 'B' + 256));
	return (0);
}*/
