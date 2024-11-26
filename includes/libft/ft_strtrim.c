/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:45:41 by sephilip          #+#    #+#             */
/*   Updated: 2023/09/20 12:04:22 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p1;
	char	*trimmed;
	size_t	s;
	size_t	e;

	s = 0;
	e = ft_strlen(s1) - 1;
	p1 = (char *)s1;
	while (p1[s] && ft_strchr(set, p1[s]))
		s++;
	while (p1[e] && ft_strchr(set, p1[e]))
		e--;
	trimmed = ft_substr(s1, s, e - s + 1);
	return (trimmed);
}
// WHAT ABOUT !S1?
/*
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	while (s1[end] && ft_strchr(set, s1[end]))
		--end;
	trimmed = ft_substr(s1, start, end - start + 1);
	return (trimmed);
}*/
/*
int	main()
{
	char	s[] = "123123";
	char	t[] = "";

	printf("%s\n", ft_strtrim(s, t));
	return (0);
}*/
