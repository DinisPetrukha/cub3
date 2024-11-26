/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:34:34 by sephilip          #+#    #+#             */
/*   Updated: 2024/01/04 14:28:53 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex_s(unsigned long num, int *counter)
{
	unsigned long	a;
	unsigned long	res;

	if (num > 15)
	{
		res = num / 16;
		ft_printhex_s(res, counter);
	}
	a = num % 16;
	if (a <= 9)
		ft_printchar(48 + a, counter);
	else
		ft_printchar(87 + a, counter);
}

void	ft_printhex(unsigned long num, int *counter)
{
	unsigned long	a;
	unsigned long	res;

	if (num > 15)
	{
		res = num / 16;
		ft_printhex(res, counter);
	}
	a = num % 16;
	if (a <= 9)
		ft_printchar(48 + a, counter);
	else
		ft_printchar(55 + a, counter);
}

void	ft_printptr(void *addr, int *counter)
{
	if (addr == NULL)
		ft_printstr("(nil)", counter);
	else
	{
		ft_printstr("0x", counter);
		ft_printhex_s((unsigned long)addr, counter);
	}
}

void	ft_separ(char c, va_list var, int *counter)
{
	if (c == 'c')
		ft_printchar(va_arg(var, int), counter);
	else if (c == 's')
		ft_printstr(va_arg(var, char *), counter);
	else if (c == 'd' || c == 'i')
		ft_printnbr(va_arg(var, int), counter);
	else if (c == 'u')
		ft_printdec(va_arg(var, unsigned int), counter);
	else if (c == '%')
		ft_printchar('%', counter);
	else if (c == 'x')
		ft_printhex_s(va_arg(var, unsigned int), counter);
	else if (c == 'X')
		ft_printhex(va_arg(var, unsigned int), counter);
	else if (c == 'p')
		ft_printptr(va_arg(var, void *), counter);
}

int	ft_printf(const char *p, ...)
{
	va_list			args;
	char			*str;
	int				counter;
	int				i;

	i = 0;
	str = (char *)p;
	if (str == NULL)
		return (-1);
	va_start(args, p);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_separ(str[i + 1], args, &counter);
			i++;
		}
		else
			ft_printchar(str[i], &counter);
		i++;
	}
	va_end(args);
	return (counter);
}
