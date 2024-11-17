/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:38:38 by sephilip          #+#    #+#             */
/*   Updated: 2024/09/29 13:18:38 by dpetrukh         ###   ########.fr       */
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

	//printf"%s\n", ft_strchr(s, 'B' + 256));
	//printf"%s\n", strchr(s, 'B' + 256));
	return (0);
}*/
