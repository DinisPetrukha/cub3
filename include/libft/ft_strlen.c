/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:11:40 by sephilip          #+#    #+#             */
/*   Updated: 2024/11/17 13:02:14 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//updated
size_t	ft_strlen(const char *s)
{
	unsigned int	size;

	size = 0;
	if (!(*s) || s == NULL)
		return (0);
	while (s[size])
		size++;
	return (size);
}
/*
int	main()
{
	char	str[] = "abcdefghij \n10012";

	//printf"%d\n", ft_strlen(str));
	//printf"%d\n", strlen(str));
	return (0);
}*/
