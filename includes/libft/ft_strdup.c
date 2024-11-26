/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:31:31 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/19 14:56:58 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(src) + 1;
	dest = (char *)malloc(len * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, src, len);
	return (dest);
}
/*
int	main()
{
	char	p1[] = "Hello1234567";
	char	*p2;
	
	p2 = ft_strdup(p1);
	printf("%s\n", p2);
	return (0);
}*/
