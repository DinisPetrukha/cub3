/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:49:10 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/25 15:56:01 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/*
int	main()
{
	int	i;
	i = open("test2.txt", O_WRONLY | O_CREAT);
	ft_putstr_fd("NOT VOID BOYS", i);
	close(i);
	return (0);
}*/
