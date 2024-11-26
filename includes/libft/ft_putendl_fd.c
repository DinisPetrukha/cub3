/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:54:16 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/20 23:10:18 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*
int	main()
{
	int	i;

	i = open("test3.txt", O_WRONLY | O_CREAT);
	ft_putendl_fd("THATS IT", i);
	ft_putendl_fd("CANT TAKE IT ANYMORE", i);
	close(i);
	return (0);
}*/
