/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:11:40 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/19 14:55:50 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
/*
int	main()
{
	char	str[] = "abcdefghij \n10012";

	printf("%d\n", ft_strlen(str));
	printf("%d\n", strlen(str));
	return (0);
}*/
