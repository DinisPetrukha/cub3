/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:41:28 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/04 16:42:04 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*p;
	char	*p2;
	int		i;

	i = 0;
	p = (char *)dest;
	p2 = (char *)src;
	while (i < n)
	{
		p[i] = p2[i];
		if (p2[i] == c)
		{
			printf("DEST: %s\n", dest);
			return (dest + i + 1);
		}
		i++;
	}
	return (dest);
}
/*
int	main()
{
	char	str[] = "OMG ITS_HIM!";
	char	postr[] = "AAAAAAAAAAAAAA";
	char	*array;
	
	array = ft_memccpy(postr, str, 72, 15);
	printf("%s\n", array);
	return (0);
}*/
