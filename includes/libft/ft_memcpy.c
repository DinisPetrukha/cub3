/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:45:12 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/12 17:38:35 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*p2;
	char		*p;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (dest);
	p = (char *)dest;
	p2 = (const char *)src;
	while (i < n)
	{
		p[i] = p2[i];
		i++;
	}
	return (dest);
}
/*
	unsigned char??
int	main()
{
	char	str[20];
	char	ptr[] = "quadro";
	char	str2[20];
	char	ptr2[] = "bolas";

	printf("%s\n", (char *)ft_memcpy(str, ptr, 6));
	printf("%s\n", (char *)memcpy(str2, ptr2, 6));
	return(0);
}*/
