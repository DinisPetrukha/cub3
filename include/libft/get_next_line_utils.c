/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephilip@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:28:15 by sephilip          #+#    #+#             */
/*   Updated: 2024/02/15 20:41:01 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_verline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlcopy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (!size)
		return (len);
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len);
}

char	*ft_inccpy(char *big, char *glued, int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!big)
		big = "";
	while (big[i])
		i++;
	if (size == 0)
	{
		while (glued[size])
			size++;
	}
	str = (char *)malloc((i + size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcopy(str, big, i + 1);
	ft_strlcopy(&(str[i]), glued, size + 1);
	if (*big)
		free(big);
	return (str);
}

char	*ft_clear(char buf[1][BUFFER_SIZE + 1], char *str, int a)
{
	if (a <= 0)
		*buf[0] = 0;
	if (a < 0)
		return (NULL);
	return (str);
}
