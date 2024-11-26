/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephilip@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:58:10 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/12 17:39:01 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
// n - 1 because the zero counts too. it goes from 0 to n - 1; KISS

/*
	or?
	ft_memset(s, 0, n);
*/
/*
int	main()
{
	void	*ptr;
	char	*str;
	int	len;
	int	i;

	i = 0;
	len = 10 + 1;
	ptr = malloc(len * sizeof(char));
	str = (char *)ptr;
	while (i < len - 1)
	{
		printf("I:%d\n", i);
		str[i] = 'H';	
		i++;
	}
	str[i] = '\0';
	printf("%s\n", str);
	ft_bzero(ptr, len);
	printf("poha: %s\n", (char *)ptr);
	printf("%s\n", str);
	return(0);
}*/
