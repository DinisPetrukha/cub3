/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:18:29 by sephilip          #+#    #+#             */
/*   Updated: 2024/01/04 14:19:31 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addcount(int	*p)
{
	int	a;

	a = *p;
	a++;
	*p = a;
}

void	ft_printchar(char c, int *counter)
{
	write(1, &c, 1);
	ft_addcount(counter);
}

void	ft_printdec(unsigned int n, int *counter)
{
	unsigned int	a;
	unsigned int	res;

	if (n > 9)
	{
		res = n / 10;
		ft_printdec(res, counter);
	}
	a = n % 10;
	ft_printchar(a + '0', counter);
}

void	ft_printstr(char *s, int *counter)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_printstr("(null)", counter);
		return ;
	}
	while (s[i])
	{
		ft_printchar(s[i], counter);
		i++;
	}
}

void	ft_printnbr(int n, int *counter)
{
	int	res;
	int	a;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*counter = *counter + 11;
	}
	else
	{
		if (n < 0)
		{
			ft_printchar('-', counter);
			n *= -1;
		}
		if (n > 9)
		{
			res = n / 10;
			ft_printnbr(res, counter);
		}
		a = n % 10;
		ft_printchar(a + '0', counter);
	}
}
