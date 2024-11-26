/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:33:46 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/20 22:48:46 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main()
{
	int	i;
	i = open("test.txt", O_WRONLY | O_CREAT);
	ft_putchar_fd('a', i);
	close(i);
	return (0);
}*/
