/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:22:09 by sephilip          #+#    #+#             */
/*   Updated: 2023/11/02 13:31:11 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

int		ft_verline(char *str);
size_t	ft_strlcopy(char *dst, const char *src, size_t size);
char	*ft_inccpy(char *big, char *glued, int size);
char	*ft_clear(char buf[1][BUFFER_SIZE + 1], char *str, int a);

#endif /*GET_NEXT_LINE_H */
