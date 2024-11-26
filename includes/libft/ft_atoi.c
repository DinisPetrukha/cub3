/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:54:43 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/04 16:37:25 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*nbr;
	int		i;
	int		res;
	int		sig;

	nbr = (char *)nptr;
	i = 0;
	res = 0;
	sig = 1;
	while (((nbr[i] >= 9) && (nbr[i] <= 13)) || nbr[i] == 32)
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sig = -sig;
		i++;
	}
	while (nbr[i] >= 48 && nbr[i] <= 57)
	{
		res = res * 10 + nbr[i] - 48;
		i++;
	}
	return (sig * res);
}
/*
int	main()
{
	char	s[] = " 	 +12345a67890";

	printf("%d\n", ft_atoi(s));
	printf("%d\n", atoi(s));
	return (0);
}*/
