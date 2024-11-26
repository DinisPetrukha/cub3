/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:36:41 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/20 21:06:35 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_n_lenght(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	ft_mod(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		sig;

	sig = 0;
	size = ft_n_lenght(n);
	if (n < 0)
		sig = 1;
	str = (char *)malloc((size + sig + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size + sig] = 0;
	while (size > 0)
	{
		if (n < 0)
			str[size + sig - 1] = (ft_mod(n % -10) + '0');
		else
			str[size + sig - 1] = (n % 10 + '0');
		n = n / 10;
		size--;
	}
	if (sig == 1)
		str[0] = '-';
	return (str);
}
/*
int	main()
{
	char *res = ft_itoa(300);
	printf("%s\n", res);
//	ft_print_result(res);
	return (0);
}*/
