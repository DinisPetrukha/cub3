/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:10:28 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/23 12:37:14 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	int	res;
	int	a;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		if (n > 9)
		{
			res = n / 10;
			ft_putnbr_fd(res, fd);
		}
		a = n % 10;
		ft_putchar_fd(a + '0', fd);
	}
}
/*
int	main()
{
	int	i;

	ft_putnbr_fd(-2147483648, 1);
//	i = open("test4.txt", O_WRONLY | O_CREAT);
//	ft_putnbr_fd(-2147483648, i);
//	close(i);
	return (0);
}*/
