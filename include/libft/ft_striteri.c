/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:06:58 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/25 15:58:40 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <unistd.h>

void	test(unsigned int i, char* b)
{
	write(1, b, 1);
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main()
{
	ft_striteri("abcdef", test);
	return(0);
}*/
