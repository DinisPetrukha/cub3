/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:16:27 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/18 16:07:07 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	n;
	char	*p1;
	char	*p2;

	i = 0;
	p1 = (char *)s1;
	p2 = (char *)s2;
	if (s2[i] == '\0')
		return (p1);
	while (p1[i] && i < len)
	{
		n = 0;
		while ((p1[i + n] == p2[n]) && (i + n) < len)
		{
			if (!p2[n + 1])
				return (&p1[i]);
			n++;
		}
		i++;
	}
	return (0);
}
/*
int	main()
{
//	char	p1[] = "AAAAA123 AAAAA123";
//	char	p2[] = " ";
	char	empty[] = "";
	char	haystack[30] = "aaabcabcd";

	printf("%p\n", empty);
//	printf("%p\n", strnstr(empty, "", -1));
	printf("%s\n", ft_strnstr(haystack, "cd", 8));
	return (0);
}*/
