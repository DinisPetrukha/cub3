/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:26:03 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/12 17:43:30 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void *s, int c, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)s;
	while (i < len)
	{
		p[i] = c;
		i++;
	}
	return (s);
}
/*
int	main()
{
	char	str[] = "Hello";

	printf("%s\n", (char *)ft_memset(str, 'l', 5));
	return (0);
}*/
/*
int	main()
{
	void	*ptr;
	char	*str;
	int	len;

	len = 0;
// openned the space for 15 but only 9
of them will be occupied later with stuff so lenght will be 9 same
	ptr = malloc(15 * sizeof(char));
	ptr = ft_memset(ptr, 49, 9);
	str = (char *)ptr;
	while (str[len])
		len++;
	str[9] = '9';
	printf("%s\n len: %d", str, len);
	return(0);
}*/
